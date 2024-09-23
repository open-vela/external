/****************************************************************************
 * external/ethercat/nuttx/linux/skbuff.c
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

#include <linux/skbuff.h>
#include <linux/slab.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

FAR struct sk_buff *dev_alloc_skb(unsigned int length)
{
  FAR uint8_t *data;
  FAR struct sk_buff *skb;

  data = kmalloc(length, GFP_KERNEL);
  if (data == NULL)
    {
      return NULL;
    }

  skb = kmalloc(sizeof(struct sk_buff), GFP_KERNEL);
  if (skb == NULL)
    {
      return NULL;
    }

  skb->head = data;
  skb->data = data;

  skb->tail = skb->data;

  return skb;
}

void skb_reserve(FAR struct sk_buff *skb, int len)
{
  skb->data += len;
  skb->tail += len;
}

FAR unsigned char *skb_push(FAR struct sk_buff *skb, unsigned int len)
{
  skb->data -= len;
  skb->len  += len;

  return skb->data;
}

void dev_kfree_skb(FAR struct sk_buff *skb)
{
  kfree(skb->head);
  kfree(skb);
}
