/****************************************************************************
 * external/ethercat/nuttx/ec_cdev.c
 *
 *   Copyright (C) 2024 Xiaomi InC. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in
 *  the documentation and/or other materials provided with the
 *  distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *  used to endorse or promote products derived from this software
 *  without specific prior written permission.
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

#include <fcntl.h>

#include <nuttx/kmalloc.h>
#include <nuttx/fs/fs.h>

#include "../ethercat/master/cdev.h"
#include "../ethercat/master/master.h"
#include "../ethercat/master/ethernet.h"
#include "../ethercat/master/ioctl.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

typedef struct
{
  FAR ec_cdev_t *cdev;    /* Character device. */
  ec_ioctl_context_t ctx; /* Context. */
} ec_cdev_priv_t;

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int ec_cdev_open(FAR struct file *filep);
static int ec_cdev_close(FAR struct file *filep);
static int ec_cdev_ioctl(FAR struct file *filep, int, unsigned long);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/** File operation callbacks for the EtherCAT character device.
 */

static const struct file_operations g_ec_cdev_ops =
{
  ec_cdev_open,  /* open */
  ec_cdev_close, /* close */
  NULL,          /* read */
  NULL,          /* write */
  NULL,          /* seek */
  ec_cdev_ioctl, /* ioctl */
  NULL,          /* mmap */
  NULL,          /* truncate */
  NULL           /* poll */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int ec_cdev_open(FAR struct file *filep)
{
  FAR struct inode *inode = filep->f_inode;
  FAR ec_cdev_t *cdev = inode->i_private;
  FAR ec_cdev_priv_t *priv;

  priv = kmm_zalloc(sizeof(ec_cdev_priv_t));
  if (priv == NULL)
    {
      EC_MASTER_ERR(cdev->master,
              "Failed to allocate memory for private data structure.\n");
      return -ENOMEM;
    }

  priv->cdev = cdev;
  priv->ctx.writable = (filep->f_oflags & O_WRONLY) != 0;

  filep->f_priv = priv;

  EC_MASTER_DBG(cdev->master, 0, "File opened.\n");
  return 0;
}

static int ec_cdev_close(FAR struct file *filep)
{
  FAR ec_cdev_priv_t *priv = (FAR ec_cdev_priv_t *)filep->f_priv;
  FAR ec_master_t *master = priv->cdev->master;

  if (priv->ctx.requested)
    {
      ecrt_release_master(master);
    }

  EC_MASTER_DBG(master, 0, "File closed.\n");

  kmm_free(priv);
  return 0;
}

static int ec_cdev_ioctl(FAR struct file *filep, int cmd, unsigned long arg)
{
  FAR ec_cdev_priv_t *priv = (FAR ec_cdev_priv_t *)filep->f_priv;

  EC_MASTER_DBG(priv->cdev->master, 0,
                "ioctl(filep = 0x%p, cmd = 0x%08x (0x%02x), arg = 0x%lx)\n",
                filep, cmd, _IOC_NR(cmd), arg);

  return ec_ioctl(priv->cdev->master, &priv->ctx, cmd, (FAR void *)arg);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int ec_cdev_init(FAR ec_cdev_t *cdev, FAR ec_master_t *master, dev_t dev_num)
{
  int ret;

  cdev->master = master;

  ret = register_driver("/dev/EtherCAT", &g_ec_cdev_ops, 0644, cdev);

  if (ret)
    {
      EC_MASTER_ERR(master, "Failed to add character device!\n");
    }

  ether_device_init();

  return ret;
}

void ec_cdev_clear(FAR ec_cdev_t *cdev)
{
  unregister_driver("/dev/EtherCAT");
}
