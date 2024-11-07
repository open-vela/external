/****************************************************************************
 * external/ethercat/nuttx/linux/kthread.c
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

#include <stdio.h>
#include <sys/types.h>

#include <nuttx/kthread.h>

#include <linux/kthread.h>
#include <linux/slab.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef kthread_create

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int kthread_work(int argc, FAR char *argv[])
{
  FAR struct task_struct *t =
      (FAR struct task_struct *)((uintptr_t)strtoul(argv[1], NULL, 16));
  int ret;

  ret = t->threadfn(t->data);
  nxsem_post(&t->semexit);

  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

FAR struct task_struct *kthread_run(CODE int (*threadfn)(FAR void *data),
                                    FAR void *data,
                                    FAR const char *name)
{
  FAR struct task_struct *t;
  FAR char *argv[2];
  char      arg1[32];
  int       ret;

  t = kmalloc(sizeof(struct task_struct), GFP_KERNEL);
  if (t == NULL)
    {
      return (FAR struct task_struct *)-ENOMEM;
    }

  t->running  = true;
  t->threadfn = threadfn;
  t->data     = data;
  nxsem_init(&t->semexit, 0, 0);

  snprintf(arg1, sizeof(arg1), "%p", t);
  argv[0] = arg1;
  argv[1] = NULL;

  ret = kthread_create(name, CONFIG_ETHERCAT_MASTER_PRIORITY,
                       CONFIG_ETHERCAT_MASTER_STACKSIZE, kthread_work, argv);
  if (ret < 0)
    {
      kfree(t);
      return (FAR struct task_struct *)(uintptr_t)ret;
    }

  t->threadid = ret;
  return t;
}

void kthread_stop(FAR struct task_struct *t)
{
  t->running = false;
  nxsem_wait(&t->semexit);
  free(t);
}

void kthread_bind(FAR struct task_struct *t, unsigned int cpu)
{
  cpu_set_t cpuset;

  if (t->running)
    {
      CPU_ZERO(&cpuset);
      CPU_SET(cpu, &cpuset);
      sched_setaffinity(t->threadid, sizeof(cpu_set_t), &cpuset);
    }
}
