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

#ifndef __STORAGE_H__
#define __STORAGE_H__

#include <errno.h>
#include <sys/statvfs.h>

/**
 * @brief Enumeration for Storage of error codes.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    STORAGE_ERROR_NONE = 0, /**< Successful */
    STORAGE_ERROR_INVALID_PARAMETER = -EINVAL, /**< Invalid parameter */
    STORAGE_ERROR_OUT_OF_MEMORY = -ENOMEM, /**< Out of memory */
    STORAGE_ERROR_NOT_SUPPORTED = -ENOTTY, /**< Storage not supported */
    STORAGE_ERROR_OPERATION_FAILED = -EIO, /**< Operation failed */
} storage_error_e;

/**
 * @brief Enumeration for the storage types.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    STORAGE_TYPE_INTERNAL, /**< Internal device storage (built-in storage in a device, non-removable) */
    STORAGE_TYPE_EXTERNAL, /**< External storage */
    STORAGE_TYPE_EXTENDED_INTERNAL, /**< Extended internal storage (External storage used as internal storage) (Since 4.0) */
} storage_type_e;

/**
 * @brief Enumeration for storage devices state.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    STORAGE_STATE_UNMOUNTABLE = -2, /**< Storage is present but cannot be mounted. Typically it happens if the file system of the storage is corrupted */
    STORAGE_STATE_REMOVED = -1, /**< Storage is not present */
    STORAGE_STATE_MOUNTED = 0, /**< Storage is present and mounted with read/write access */
    STORAGE_STATE_MOUNTED_READ_ONLY = 1, /**< Storage is present and mounted with read only access */
} storage_state_e;

/**
 * @brief Called to get information once for each supported storage.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] storage_id The unique storage ID
 * @param[in] type The type of the storage
 * @param[in] state The current state of the storage
 * @param[in] path The absolute path to the root directory of the storage
 * @param[in] user_data The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n
 *         otherwise @c false to break out of the loop
 * @pre storage_foreach_device_supported() will invoke this callback function.
 * @see storage_foreach_device_supported()
 */
typedef bool (*storage_device_supported_cb)(int storage_id, storage_type_e type,
    storage_state_e state, const char* path, void* user_data);

/**
 * @brief Retrieves all the storage in a device.
 * @details This function invokes the callback function once for each storage in a device. \n
 *          If storage_device_supported_cb() returns @c false, then the iteration will be finished.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] callback The iteration callback function
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #STORAGE_ERROR_NONE Successful
 * @retval #STORAGE_ERROR_INVALID_PARAMETER Invalid parameter
 * @post This function invokes storage_device_supported_cb() repeatedly for each supported device.
 * @see storage_device_supported_cb()
 */
int storage_foreach_device_supported(storage_device_supported_cb callback, void* user_data);

/**
 * @brief Gets the internal memory size.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[out] buf A pointer to a statvfs structure
 * @return @c 0 on success,
 *         otherwise a negative error value on failure
 * @retval #STORAGE_ERROR_NONE Successful
 * @retval #STORAGE_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #STORAGE_ERROR_OPERATION_FAILED Operation failed
 * @par Example:
 * @code
 *      ...
 *  struct statvfs s;
 *      if (storage_get_internal_memory_size(&s) < 0)
 *      dlog_print(DLOG_DEBUG, LOG_TAG, "Fail to get internal memory size");
 *      else
 *              dlog_print(DLOG_DEBUG, LOG_TAG, "Total mem : %lf, Avail mem : %lf",
 *                              (double)s.f_frsize*s.f_blocks, (double)s.f_bsize*s.f_bavail);
 *      ...
 * @endcode
 */
int storage_get_internal_memory_size(struct statvfs* buf);

#endif /* __STORAGE_H__ */
