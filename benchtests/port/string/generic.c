/****************************************************************************
 * apps/external/benchtests/port/string/generic.c
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

#include <string.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: generic_memcpy
 ****************************************************************************/

void *
generic_memcpy(void *dstpp, const void *srcpp, size_t len)
{
  return memcpy(dstpp, srcpp, len);
}

/****************************************************************************
 * Name: generic_memmove
 ****************************************************************************/

void *
generic_memmove(void *a1, const void *a2, size_t len)
{
  return memmove(a1, a2, len);
}

/****************************************************************************
 * Name: generic_memset
 ****************************************************************************/

void *
generic_memset(void *dstpp, int c, size_t len)
{
  return memset(dstpp, c, len);
}

/****************************************************************************
 * Name: generic_strlen
 ****************************************************************************/

size_t
generic_strlen(const char *str)
{
  return strlen(str);
}

/****************************************************************************
 * Name: generic_strnlen
 ****************************************************************************/

size_t
generic_strnlen(const char *str, size_t maxlen)
{
  return strnlen(str, maxlen);
}
