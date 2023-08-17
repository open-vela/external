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

#ifndef __METADATA_EXTRACTOR_H__
#define __METADATA_EXTRACTOR_H__

#include <errno.h>

#include "media_info_private.h"

typedef enum {
    METADATA_EXTRACTOR_ERROR_NONE = 0, /**< Successful */
    METADATA_EXTRACTOR_ERROR_INVALID_PARAMETER = -EINVAL, /**< Invalid parameter */
    METADATA_EXTRACTOR_ERROR_OUT_OF_MEMORY = -ENOMEM, /**< Out of memory */
    METADATA_EXTRACTOR_ERROR_FILE_EXISTS = -ENOENT, /**< File does not exist */
    METADATA_EXTRACTOR_ERROR_PERMISSION_DENIED = -EACCES, /**< Permission denied */
    METADATA_EXTRACTOR_ERROR_OPERATION_FAILED = -EIO, /**< Invalid internal operation */
} metadata_extractor_error_e;

typedef enum {
    METADATA_DURATION = 0, /**< Duration */
    METADATA_VIDEO_BITRATE, /**< Video Bitrate */
    METADATA_VIDEO_FPS, /**< Video FPS */
    METADATA_VIDEO_WIDTH, /**< Video Width */
    METADATA_VIDEO_HEIGHT, /**< Video Height */
    METADATA_HAS_VIDEO, /**< Video stream count */
    METADATA_AUDIO_BITRATE, /**< Audio Bitrate */
    METADATA_AUDIO_CHANNELS, /**< Audio Channels */
    METADATA_AUDIO_SAMPLERATE, /**< Audio Samplerate */
    METADATA_AUDIO_BITPERSAMPLE, /**< Audio bit per sample */
    METADATA_HAS_AUDIO, /**< Audio stream count */
    METADATA_ARTIST, /**< Artist */
    METADATA_TITLE, /**< Title */
    METADATA_ALBUM, /**< Album */
    METADATA_ALBUM_ARTIST, /**< Album_Artist */
    METADATA_GENRE, /**< Genre */
    METADATA_COMPOSER, /**< Composer */
    METADATA_COPYRIGHT, /**< Copyright */
    METADATA_DATE, /**< Date */
    METADATA_DESCRIPTION, /**< Description */
    METADATA_COMMENT, /**< Comment */
    METADATA_TRACK_NUM, /**< Track number info */
    METADATA_CLASSIFICATION, /**< Classification */
    METADATA_RATING, /**< Rating */
    METADATA_LONGITUDE, /**< Longitude */
    METADATA_LATITUDE, /**< Latitude */
    METADATA_ALTITUDE, /**< Altitude */
    METADATA_CONDUCTOR, /**< Conductor */
    METADATA_UNSYNCLYRICS, /**< Unsynchronized lyric */
    METADATA_SYNCLYRICS_NUM, /**< Synchronized lyric (time/lyric set) number */
    METADATA_RECDATE, /**< Recording date */
    METADATA_ROTATE, /**< Rotate(Orientation) Information */
    METADATA_VIDEO_CODEC, /**< Video Codec (Since 3.0) */
    METADATA_AUDIO_CODEC, /**< Audio Codec (Since 3.0) */
    METADATA_360, /**< Flag indicating if the video is a spherical video (Since 3.0) */
} metadata_extractor_attr_e;

typedef void* MMHandleType; /**< Handle type */

typedef struct {
    char* path;
    void* buffer;
    int buffer_size;
    bool extract_meta;

    int audio_track_cnt;
    int video_track_cnt;

    MMHandleType attr_h;
    MMHandleType tag_h;
} metadata_extractor_s;

typedef struct metadata_extractor_s* metadata_extractor_h;

#endif /* __METADATA_EXTRACTOR_H__ */
