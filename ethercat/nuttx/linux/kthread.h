/****************************************************************************
 * external/ethercat/nuttx/linux/kthread.h
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

#ifndef __LINUX_KTHREAD_H
#define __LINUX_KTHREAD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/semaphore.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define kthread_create        kthread_run
#define kthread_should_stop() (!master->thread->running)
#define wake_up_process(t)    0

/****************************************************************************
 * Public Type Definitions
 ****************************************************************************/

struct task_struct
{
  pid_t threadid;
  bool running;
  CODE int (*threadfn)(FAR void *data);
  FAR void *data;
  sem_t semexit;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

FAR struct task_struct *kthread_run(CODE int (*threadfn)(FAR void *data),
                                    FAR void *data,
                                    FAR const char *name);
void kthread_stop(FAR struct task_struct *t);
void kthread_bind(FAR struct task_struct *t, unsigned int cpu);

#endif /* __LINUX_KTHREAD_H */
