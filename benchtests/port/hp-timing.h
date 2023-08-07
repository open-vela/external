/****************************************************************************
 * apps/external/benchtests/port/hp-timing.h
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

#ifndef BENCHTESTS_PORT_HP_TIMING_H
#define BENCHTESTS_PORT_HP_TIMING_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/arch.h>
#include <nuttx/clock.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

typedef uint64_t hp_timing_t;
#define HP_TIMING_NOW(var)               (var) = up_perf_gettime()
#define HP_TIMING_DIFF(diff, start, end) (diff) = (end) - (start)
#define HP_TIMING_ACCUM_NT(sum, diff)    (sum) += (diff)

#endif