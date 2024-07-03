/****************************************************************************
 * apps/external/benchtests/port/ifunc-impl-list.c
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

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>

#include "ifunc-impl-list.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: __libc_ifunc_impl_list
 ****************************************************************************/

size_t
__libc_ifunc_impl_list(const char *name, struct libc_ifunc_impl *array,
                       size_t max)
{
#ifndef bzero
  IFUNC_IMPL(max, name, bzero,
             IFUNC_IMPL_ADD(array, max, bzero, 1, bzero));
#endif

  IFUNC_IMPL(max, name, memccpy,
             IFUNC_IMPL_ADD(array, max, memccpy, 1, memccpy));

  IFUNC_IMPL(max, name, memchr,
             IFUNC_IMPL_ADD(array, max, memchr, 1, memchr));

  IFUNC_IMPL(max, name, memcmp,
             IFUNC_IMPL_ADD(array, max, memcmp, 1, memcmp));

  IFUNC_IMPL(max, name, memcpy,
             IFUNC_IMPL_ADD(array, max, memcpy, 1, memcpy));

  IFUNC_IMPL(max, name, memmem,
             IFUNC_IMPL_ADD(array, max, memmem, 1, memmem));

  IFUNC_IMPL(max, name, memmove,
             IFUNC_IMPL_ADD(array, max, memmove, 1, memmove));

  IFUNC_IMPL(max, name, mempcpy,
             IFUNC_IMPL_ADD(array, max, mempcpy, 1, mempcpy));

  IFUNC_IMPL(max, name, memrchr,
             IFUNC_IMPL_ADD(array, max, memrchr, 1, memrchr));

  IFUNC_IMPL(max, name, memset,
             IFUNC_IMPL_ADD(array, max, memset, 1, memset));

  IFUNC_IMPL(max, name, rawmemchr,
             IFUNC_IMPL_ADD(array, max, rawmemchr, 1, rawmemchr));

  IFUNC_IMPL(max, name, stpcpy,
             IFUNC_IMPL_ADD(array, max, stpcpy, 1, stpcpy));

  IFUNC_IMPL(max, name, stpncpy,
             IFUNC_IMPL_ADD(array, max, stpncpy, 1, stpncpy));

  IFUNC_IMPL(max, name, strcasecmp,
             IFUNC_IMPL_ADD(array, max, strcasecmp, 1, strcasecmp));

  IFUNC_IMPL(max, name, strcasestr,
             IFUNC_IMPL_ADD(array, max, strcasestr, 1, strcasestr));

  IFUNC_IMPL(max, name, strcat,
             IFUNC_IMPL_ADD(array, max, strcat, 1, strcat));

  IFUNC_IMPL(max, name, strchr,
             IFUNC_IMPL_ADD(array, max, strchr, 1, strchr));

  IFUNC_IMPL(max, name, strchrnul,
             IFUNC_IMPL_ADD(array, max, strchrnul, 1, strchrnul));

  IFUNC_IMPL(max, name, strcmp,
             IFUNC_IMPL_ADD(array, max, strcmp, 1, strcmp));

  IFUNC_IMPL(max, name, strcpy,
             IFUNC_IMPL_ADD(array, max, strcpy, 1, strcpy));

  IFUNC_IMPL(max, name, strcspn,
             IFUNC_IMPL_ADD(array, max, strcspn, 1, strcspn));

  IFUNC_IMPL(max, name, strlen,
             IFUNC_IMPL_ADD(array, max, strlen, 1, strlen));

  IFUNC_IMPL(max, name, strncasecmp,
             IFUNC_IMPL_ADD(array, max, strncasecmp, 1, strncasecmp));

  IFUNC_IMPL(max, name, strncat,
             IFUNC_IMPL_ADD(array, max, strncat, 1, strncat));

  IFUNC_IMPL(max, name, strncmp,
             IFUNC_IMPL_ADD(array, max, strncmp, 1, strncmp));

  IFUNC_IMPL(max, name, strncpy,
             IFUNC_IMPL_ADD(array, max, strncpy, 1, strncpy));

  IFUNC_IMPL(max, name, strnlen,
             IFUNC_IMPL_ADD(array, max, strnlen, 1, strnlen));

  IFUNC_IMPL(max, name, strtok,
             IFUNC_IMPL_ADD(array, max, strtok, 1, strtok));
  IFUNC_IMPL(max, name, strpbrk,
             IFUNC_IMPL_ADD(array, max, strpbrk, 1, strpbrk));

  IFUNC_IMPL(max, name, strrchr,
             IFUNC_IMPL_ADD(array, max, strrchr, 1, strrchr));

  IFUNC_IMPL(max, name, strsep,
             IFUNC_IMPL_ADD(array, max, strsep, 1, strsep));

  IFUNC_IMPL(max, name, strspn,
             IFUNC_IMPL_ADD(array, max, strspn, 1, strspn));

  IFUNC_IMPL(max, name, strstr,
             IFUNC_IMPL_ADD(array, max, strstr, 1, strstr));

  IFUNC_IMPL(max, name, strtok,
             IFUNC_IMPL_ADD(array, max, strtok, 1, strtok));

  IFUNC_IMPL(max, name, wctomb,
             IFUNC_IMPL_ADD(array, max, wctomb, 1, wctomb));

  IFUNC_IMPL(max, name, wcscat,
             IFUNC_IMPL_ADD(array, max, wcscat, 1, wcscat));

  IFUNC_IMPL(max, name, wcschr,
             IFUNC_IMPL_ADD(array, max, wcschr, 1, wcschr));

  IFUNC_IMPL(max, name, wcscmp,
             IFUNC_IMPL_ADD(array, max, wcscmp, 1, wcscmp));

  IFUNC_IMPL(max, name, wcscpy,
             IFUNC_IMPL_ADD(array, max, wcscpy, 1, wcscpy));

  IFUNC_IMPL(max, name, wcslen,
             IFUNC_IMPL_ADD(array, max, wcslen, 1, wcslen));

  IFUNC_IMPL(max, name, wcscspn,
             IFUNC_IMPL_ADD(array, max, wcscspn, 1, wcscspn));

  IFUNC_IMPL(max, name, wcslen,
             IFUNC_IMPL_ADD(array, max, wcslen, 1, wcslen));

  IFUNC_IMPL(max, name, wcsncat,
             IFUNC_IMPL_ADD(array, max, wcsncat, 1, wcsncat));

  IFUNC_IMPL(max, name, wcsncpy,
             IFUNC_IMPL_ADD(array, max, wcsncpy, 1, wcsncpy));

  IFUNC_IMPL(max, name, wcspbrk,
             IFUNC_IMPL_ADD(array, max, wcspbrk, 1, wcspbrk));

  IFUNC_IMPL(max, name, wcsrchr,
             IFUNC_IMPL_ADD(array, max, wcsrchr, 1, wcsrchr));

  IFUNC_IMPL(max, name, wcsspn,
             IFUNC_IMPL_ADD(array, max, wcsspn, 1, wcsspn));

  IFUNC_IMPL(max, name, wmemchr,
             IFUNC_IMPL_ADD(array, max, wmemchr, 1, wmemchr));

  IFUNC_IMPL(max, name, wmemcmp,
             IFUNC_IMPL_ADD(array, max, wmemcmp, 1, wmemcmp));

  IFUNC_IMPL(max, name, wmemset,
             IFUNC_IMPL_ADD(array, max, wmemset, 1, wmemset));

  return 0;
}
