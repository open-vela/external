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

#ifndef __MEDIA_INFO_PRIVATE_H__
#define __MEDIA_INFO_PRIVATE_H__

typedef struct {
    char* media_id;
    char* album;
    char* artist;
    char* album_artist;
    char* genre;
    char* composer;
    char* year;
    char* recorded_date;
    char* copyright;
    char* track_num;
    int bitrate;
    int duration;
    int width;
    int height;
    int rotation;
} video_meta_s;

typedef struct video_meta_s* video_meta_h;

typedef struct {
    char* media_id;
    char* album;
    char* artist;
    char* album_artist;
    char* genre;
    char* composer;
    char* year;
    char* recorded_date;
    char* copyright;
    char* track_num;
    int bitrate;
    int bitpersample;
    int samplerate;
    int channel;
    int duration;
} audio_meta_s;

typedef struct audio_meta_s* audio_meta_h;

typedef struct {
    char* media_id;
    int width;
    int height;
    char* date_taken;
    char* exposure_time;
    double fnumber;
    int iso;
    char* model;
    media_content_orientation_e orientation;
} image_meta_s;

typedef struct image_meta_s* image_meta_h;

typedef struct {
    char* media_id;
    char* file_path;
    char* display_name;
    media_content_type_e media_type;
    char* mime_type;
    unsigned long long size;
    time_t added_time;
    time_t modified_time;
    time_t timeline;
    char* thumbnail_path;
    char* description;
    double longitude;
    double latitude;
    double altitude;
    int rating;
    time_t favourite;
    char* title;
    int is_drm;
    int storage_type;
    char* storage_uuid;
    unsigned int request_id;
    unsigned int face_request_id;
    int is_360;
    image_meta_s* image_meta;
    video_meta_s* video_meta;
    audio_meta_s* audio_meta;
} media_info_s;

typedef struct media_info_s* media_info_h;

typedef struct {
    char* key; /**< Key string */
    char* value; /**< Value string */
} filter_s;

typedef struct filter_s* filter_h;

#endif /* __MEDIA_INFO_PRIVATE_H__ */
