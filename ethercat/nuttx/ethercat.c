/****************************************************************************
 * external/ethercat/nuttx/ethercat.c
 *
 *   Copyright (C) 2024 Xiaomi InC. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/queue.h>

#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netpacket/packet.h>

#include <linux/netdevice.h>
#include <linux/skbuff.h>

#include "../ethercat/devices/ecdev.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define ETH_P_ECAT 0x88A4    /* Ether type: EtherCat Protocol */

struct ether_device
{
  struct net_device dev;
  FAR struct ec_device *ec;
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int ether_device_open(FAR struct net_device *dev);
static int ether_device_stop(FAR struct net_device *dev);
static int ether_device_start_xmit(FAR struct sk_buff *skb,
                                   FAR struct net_device *dev);
static void ether_device_poll(FAR struct net_device *dev);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const unsigned char g_ether_device_mac[] =
{
  0x02, 0x02, 0x03, 0x04, 0x05, 0x06
};

struct net_device_ops g_ether_device_ops =
{
  .ndo_open       = ether_device_open,
  .ndo_stop       = ether_device_stop,
  .poll           = ether_device_poll,
  .ndo_start_xmit = ether_device_start_xmit
};

struct ether_device g_ether_device =
{
  {
    .name       = "dummy",
    .dev_addr   = g_ether_device_mac,
    .netdev_ops = &g_ether_device_ops,
  }
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int ether_device_open(FAR struct net_device *dev)
{
  FAR struct ether_device *ethdev = (FAR struct ether_device *)dev;
  struct sockaddr_ll sll;
  struct timeval timeout;
  struct ifreq ifr;
  int ifindex;
  int i;
  int ret;

  ret = psock_socket(AF_PACKET, SOCK_RAW | SOCK_NONBLOCK,
                     HTONS(ETH_P_ECAT), &ethdev->dev.sock);
  if (ret < 0)
    {
      return ret;
    }

  memset(&sll, 0, sizeof(struct sockaddr_ll));

  timeout.tv_sec  = 0;
  timeout.tv_usec = 1;

  psock_setsockopt(&ethdev->dev.sock, SOL_SOCKET, SO_RCVTIMEO, &timeout,
                    sizeof(timeout));
  psock_setsockopt(&ethdev->dev.sock, SOL_SOCKET, SO_SNDTIMEO, &timeout,
                    sizeof(timeout));

  i = 1;
  psock_setsockopt(&ethdev->dev.sock, SOL_SOCKET, SO_DONTROUTE, &i,
                    sizeof(i));

  /* connect socket to NIC by name */

  strlcpy(ethdev->dev.name, CONFIG_ETHERCAT_MASTER_IFNAME,
          sizeof(ethdev->dev.name));
  strlcpy(ifr.ifr_name, CONFIG_ETHERCAT_MASTER_IFNAME, sizeof(ifr.ifr_name));
  psock_ioctl(&ethdev->dev.sock, SIOCGIFINDEX, &ifr);
  ifindex = ifr.ifr_ifindex;
  ifr.ifr_flags = 0;

  /* reset flags of NIC interface */

  psock_ioctl(&ethdev->dev.sock, SIOCGIFFLAGS, &ifr);

  /* set flags of NIC interface, here promiscuous and broadcast */

  ifr.ifr_flags = ifr.ifr_flags | IFF_BROADCAST;
  psock_ioctl(&ethdev->dev.sock, SIOCGIFFLAGS, &ifr);

  sll.sll_family   = AF_PACKET;
  sll.sll_protocol = HTONS(ETH_P_ECAT);
  sll.sll_ifindex  = ifindex;

  ret = psock_bind(&ethdev->dev.sock, (FAR struct sockaddr *)&sll,
                   sizeof(struct sockaddr_ll));
  if (ret < -1)
    {
      psock_close(&ethdev->dev.sock);
      return ret;
    }

  ecdev_set_link(ethdev->ec, 1);
  return 0;
}

static int ether_device_stop(FAR struct net_device *dev)
{
  return 0;
}

static int ether_device_start_xmit(FAR struct sk_buff *skb,
                                   FAR struct net_device *dev)
{
  FAR struct ether_device *ethdev = (FAR struct ether_device *)dev;

  /* use raw socket send as ether_device_start_xmit */

  return psock_send(&ethdev->dev.sock, skb->data, skb->len, 0);
}

static void ether_device_poll(FAR struct net_device *dev)
{
  FAR struct ether_device *ethdev = (FAR struct ether_device *)dev;
  char frame[CONFIG_NET_ETH_PKTSIZE];
  ssize_t len;

  /* use raw socket receive as poll */

  len = psock_recv(&ethdev->dev.sock, frame, CONFIG_NET_ETH_PKTSIZE, 0);
  if (len > 0)
    {
      ecdev_receive(ethdev->ec, frame, len);
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

void ether_device_init(void)
{
  g_ether_device.ec = ecdev_offer(
                    (FAR struct net_device *)&g_ether_device,
                    g_ether_device.dev.netdev_ops->poll, NULL);
  ecdev_open(g_ether_device.ec);
}
