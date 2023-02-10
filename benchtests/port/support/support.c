/****************************************************************************
 * apps/external/benchtests/port/support/support.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#include <intprops.h>
#include <support/support.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static void
dummy_alrm_handler(int sig)
{
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: support_create_timer
 ****************************************************************************/

timer_t support_create_timer(uint64_t sec, long int nsec, bool repeat,
                             void (*callback)(int))
{
  struct sigaction sa;
  sa.sa_handler = callback != NULL ? callback : dummy_alrm_handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGALRM, &sa, NULL);

  struct sigevent ev =
    {
      .sigev_notify = SIGEV_SIGNAL,
      .sigev_signo = SIGALRM
    };

  timer_t timerid;
  int r = timer_create(CLOCK_REALTIME, &ev, &timerid);
  if (r == -1)
    {
      exit(1);
    }

  /* Single timer with 0.1s.  */

  struct itimerspec its =
    {
      { .tv_sec = repeat ? sec : 0, .tv_nsec = repeat ? nsec : 0 },
      { .tv_sec = sec, .tv_nsec = nsec }
    };

  r = timer_settime(timerid, 0, &its, NULL);
  if (r == -1)
    {
      exit(1);
    }

  return timerid;
}

/****************************************************************************
 * Name: support_delete_timer
 ****************************************************************************/

/* Disable the timer TIMER.  */

void support_delete_timer(timer_t timer)
{
  int r = timer_delete(timer);
  if (r == -1)
    {
      exit(1);
    }

  signal(SIGALRM, SIG_DFL);
}

/****************************************************************************
 * Name: set_fortify_handler
 ****************************************************************************/

void set_fortify_handler(void (*handler)(int sig))
{
  struct sigaction sa;

  sa.sa_handler = handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);

  sigaction(SIGABRT, &sa, NULL);
}

/****************************************************************************
 * Name: xasprintf
 ****************************************************************************/

char *xasprintf(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  char *result;
  if (vasprintf(&result, format, ap) < 0)
    {
      exit(1);
    }

  va_end(ap);
  return result;
}
