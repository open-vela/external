/****************************************************************************
 * apps/external/glibc/port/config.h
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

/* Define if CC compiler accepts -ftree-loop-distribute-patterns.  */

#undef HAVE_CC_INHIBIT_LOOP_TO_LIBCALL

/* Define if TEST_CC compiler accepts -ftree-loop-distribute-patterns.  */

#undef HAVE_TEST_CC_INHIBIT_LOOP_TO_LIBCALL

/* Define to 1 if the assembler needs intermediate aliases to define
 * multiple symbol versions for one symbol.
 */
#define SYMVER_NEEDS_ALIAS 0
