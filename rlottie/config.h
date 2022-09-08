/****************************************************************************
 * external/rlottie/config.h
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

#pragma once

#include <nuttx/config.h>

#ifdef CONFIG_LOTTIE_MODULE
#  define LOTTIE_IMAGE_MODULE_SUPPORT
#ifdef CONFIG_LOTTIE_MODULE_PATH
#  define LOTTIE_IMAGE_MODULE_PLUGIN CONFIG_LOTTIE_MODULE_PATH
#endif
#endif

#ifdef CONFIG_LOTTIE_THREAD_SUPPORT
#  define LOTTIE_THREAD_SUPPORT
#endif

#ifdef CONFIG_LOTTIE_CACHE_SUPPORT
#  define LOTTIE_CACHE_SUPPORT
#endif

#ifdef CONFIG_LOTTIE_LOGGING_SUPPORT
#  define  LOTTIE_LOGGING_SUPPORT
#endif
