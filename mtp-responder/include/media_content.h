/*
 * Copyright (C) 2023 Xiaomi Corperation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MEDIA_CONTENT_H__
#define __MEDIA_CONTENT_H__

#include <errno.h>

typedef enum {
    MEDIA_CONTENT_ERROR_NONE = 0, /**< Successful */
    MEDIA_CONTENT_ERROR_INVALID_PARAMETER = -EINVAL, /**< Invalid parameter */
    MEDIA_CONTENT_ERROR_OUT_OF_MEMORY = -ENOMEM, /**< Out of memory */
    MEDIA_CONTENT_ERROR_INVALID_OPERATION = -EINVAL, /**< Invalid Operation */
    MEDIA_CONTENT_FILE_NO_SPACE_ON_DEVICE = -ENOSPC, /**< No space left on device */
    MEDIA_CONTENT_ERROR_PERMISSION_DENIED = -EACCES, /**< Permission denied */
    MEDIA_CONTENT_ERROR_DB_FAILED = -EIO, /**< DB operation failed */
    MEDIA_CONTENT_ERROR_DB_BUSY = -EBUSY, /**< DB operation BUSY */
    MEDIA_CONTENT_ERROR_NETWORK = -EREMOTEIO, /**< Network Fail */
    MEDIA_CONTENT_ERROR_UNSUPPORTED_CONTENT = -ENOTTY, /**< Unsupported Content */
    MEDIA_CONTENT_ERROR_NOT_SUPPORTED = -ENOTSUP, /**< Not supported */
} media_content_error_e;

typedef enum {
    MEDIA_CONTENT_TYPE_IMAGE = 0, /**<The type of an image */
    MEDIA_CONTENT_TYPE_VIDEO = 1, /**<The type of a video */
    MEDIA_CONTENT_TYPE_SOUND = 2, /**<The type of sound */
    MEDIA_CONTENT_TYPE_MUSIC = 3, /**<The type of music */
    MEDIA_CONTENT_TYPE_OTHERS = 4, /**<The type of other */
} media_content_type_e;

typedef enum {
    MEDIA_CONTENT_ORIENTATION_NOT_AVAILABLE = 0, /**< Not available*/
    MEDIA_CONTENT_ORIENTATION_NORMAL = 1, /**< Normal*/
    MEDIA_CONTENT_ORIENTATION_HFLIP = 2, /**< Flip horizontal*/
    MEDIA_CONTENT_ORIENTATION_ROT_180 = 3, /**< Rotate 180 degrees*/
    MEDIA_CONTENT_ORIENTATION_VFLIP = 4, /**< Flip vertical*/
    MEDIA_CONTENT_ORIENTATION_TRANSPOSE = 5, /**< Transpose*/
    MEDIA_CONTENT_ORIENTATION_ROT_90 = 6, /**< Rotate 90 degrees*/
    MEDIA_CONTENT_ORIENTATION_TRANSVERSE = 7, /**< Transverse*/
    MEDIA_CONTENT_ORIENTATION_ROT_270 = 8, /**< Rotate 270 degrees*/
} media_content_orientation_e;

typedef enum {
    MEDIA_CONTENT_COLLATE_DEFAULT = 0, /**< Default collation BINARY */
    MEDIA_CONTENT_COLLATE_NOCASE = 1, /**< Collation NOCASE, not case sensitive */
    MEDIA_CONTENT_COLLATE_RTRIM = 2, /**< Collation RTRIM, trailing space characters are ignoed */
    MEDIA_CONTENT_COLLATE_LOCALIZED = 3, /**< Collation LOCALIZATION, NOCASE also applied */
} media_content_collation_e;

/**
 * @brief Disconnects from the media content service.
 * @details This function closes connection to the media content service. Any further media content related operation
 *          cannot be performed after this function is called.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @return @c 0 on success,
 *         otherwise a negative error value
 *
 * @retval #MEDIA_CONTENT_ERROR_NONE      Successful
 * @retval #MEDIA_CONTENT_ERROR_DB_FAILED DB operation failed
 *
 * @pre media_content_connect()
 *
 * @see media_content_connect()
 *
 */
int media_content_disconnect(void);

#endif /* __MEDIA_CONTENT_H__ */
