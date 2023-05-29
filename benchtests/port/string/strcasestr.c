/****************************************************************************
 * apps/external/benchtests/port/string/strcasestr.c
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

#include <ctype.h>
#include <string.h>
#include <sys/types.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: simple_strcasestr
 ****************************************************************************/

static char *simple_strcasestr(const char *s1, const char *s2)
{
  ssize_t s1len = strlen(s1);
  ssize_t s2len = strlen(s2);

  if (s2len > s1len)
    {
      return NULL;
    }

  for (ssize_t i = 0; i <= s1len - s2len; ++i)
    {
      size_t j;
      for (j = 0; j < s2len; ++j)
        {
          if (tolower(s1[i + j]) != tolower(s2[j]))
            {
              break;
            }

          if (j == s2len)
            {
              return (char *)s1 + i;
            }
        }
    }

  return NULL;
}
