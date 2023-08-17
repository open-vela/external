/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __SYSTEM_INFO_H_
#define __SYSTEM_INFO_H_

#include <errno.h>

#define SYSTEM_INFO_ERROR_NONE 0 /**< Successful */
#define SYSTEM_INFO_ERROR_INVALID_PARAMETER -EINVAL /**< Invalid parameter */
#define SYSTEM_INFO_ERROR_OUT_OF_MEMORY -ENOMEM /**< Out of memory */
#define SYSTEM_INFO_ERROR_IO_ERROR -EIO /**< An input/output error occurred when reading value from system */
#define SYSTEM_INFO_ERROR_PERMISSION_DENIED -EACCES /**< No permission to use the API */
#define SYSTEM_INFO_ERROR_NOT_SUPPORTED -ENOTTY /**< Not supported parameter (Since 3.0) */

int system_info_get_platform_string(const char* key, char** value);

#endif /* __SYSTEM_INFO_H_ */
