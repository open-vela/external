/****************************************************************************
 * apps/external/glibc/port/error.h
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

#ifndef _ERROR_H_
#define _ERROR_H_

#include <assert.h>
#include <stdio.h>

static inline void
error (int __status, int __errnum, const char *__format, ...)
{
  va_list args;
  char buffer[256];
  va_start (args, __format);
  vsnprintf (buffer, sizeof (buffer), __format, args);
  va_end (args);
  fprintf (stderr, "error %d: %s\n", __errnum, buffer);
  __assert (__FILE__, __LINE__, buffer);
}

#endif
