/****************************************************************************
 * apps/external/benchtests/port/support/xthread.h
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

#ifndef BENCHTESTS_PORT_SUPPORT_XTHREAD_H
#define BENCHTESTS_PORT_SUPPORT_XTHREAD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <pthread.h>

/* xthread */

void xpthread_attr_init(pthread_attr_t *attr);
void xpthread_attr_setstacksize(pthread_attr_t *attr,
                                size_t stacksize);
void xpthread_attr_setguardsize(pthread_attr_t *attr,
                                size_t guardsize);
pthread_t xpthread_create(pthread_attr_t *attr,
                          void *(*thread_func)(void *), void *closure);
void *xpthread_join(pthread_t thr);

#endif
