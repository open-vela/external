/****************************************************************************
 * external/ethercat/nuttx/linux/err.h
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

#ifndef __LINUX_ERR_H
#define __LINUX_ERR_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <errno.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef errno

#define MAX_ERRNO 4095

#define IS_ERR_VALUE(x) \
        ((unsigned long)(FAR void *)(x) >= (unsigned long)-MAX_ERRNO)

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

static inline FAR void *ERR_PTR(long error)
{
    return (FAR void *)error;
}

static inline int IS_ERR(FAR const void *ptr)
{
    return IS_ERR_VALUE(ptr);
}

static inline long PTR_ERR(FAR const void *ptr)
{
    return (long)ptr;
}

#endif /* __LINUX_ERR_H */
