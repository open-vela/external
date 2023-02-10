/****************************************************************************
 * apps/external/benchtests/port/support/timespec.c
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
#include <time.h>
#include <intprops.h>
#include <support/timespec.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: timespec_sub
 ****************************************************************************/

struct timespec timespec_sub(struct timespec a, struct timespec b)
{
  time_t rs = a.tv_sec;
  time_t bs = b.tv_sec;
  int ns = a.tv_nsec - b.tv_nsec;
  int rns = ns;

  if (ns < 0)
    {
      rns = ns + TIMESPEC_HZ;
      time_t bs1;
      if (!INT_ADD_WRAPV(bs, 1, &bs1))
        {
          bs = bs1;
        }
      else if (-TYPE_SIGNED(time_t) < rs)
        {
          rs--;
        }
      else
        {
          goto low_overflow;
        }
    }

  if (INT_SUBTRACT_WRAPV(rs, bs, &rs))
    {
      if (0 < bs)
        {
        low_overflow:
          rs = TYPE_MINIMUM(time_t);
          rns = 0;
        }
      else
        {
          rs = TYPE_MAXIMUM(time_t);
          rns = TIMESPEC_HZ - 1;
        }
    }

  return (struct timespec)
         {
           .tv_sec = rs,
           .tv_nsec = rns
         };
}
