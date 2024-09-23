/****************************************************************************
 * external/ethercat/nuttx/linux/wait.h
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

#ifndef __LINUX_WAIT_H
#define __LINUX_WAIT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/semaphore.h>
#include <nuttx/mutex.h>
#include <linux/jiffies.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define __wait_event(q,c,i)                         \
({                                                  \
  int __ret = 0;                                    \
  while (!(c))                                      \
    {                                               \
      if (i)                                        \
        {                                           \
          __ret = nxsem_wait(&(q));                 \
        }                                           \
      else                                          \
        {                                           \
          __ret = nxsem_wait_uninterruptible(&(q)); \
        }                                           \
    }                                               \
  __ret;                                            \
})

#define wait_event(q, c)               __wait_event(q, c, 0)
#define wait_event_interruptible(q, c) __wait_event(q, c, 1)

/****************************************************************************
 * Public Type Definitions
 ****************************************************************************/

typedef sem_t wait_queue_head_t;

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

inline int init_waitqueue_head(FAR wait_queue_head_t *q)
{
  nxsem_init(q, 0, 0);

  return OK;
}

inline int wake_up_interruptible(FAR wait_queue_head_t *q)
{
  return nxsem_post(q);
}

inline void wake_up_all(FAR wait_queue_head_t *q)
{
  int semval;

  while (nxsem_get_value(q, &semval) >= 0 && semval <= 0)
    {
      nxsem_post(q);
    }
}

#endif /* __LINUX_WAIT_H */
