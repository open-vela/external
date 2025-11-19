/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2020, Google Inc.
 *
 * Tracepoints with lttng
 *
 * This file is auto-generated. Do not edit.
 */
#ifndef __LIBCAMERA_INTERNAL_TRACEPOINTS_H__
#define __LIBCAMERA_INTERNAL_TRACEPOINTS_H__

#if HAVE_TRACING
#define LIBCAMERA_TRACEPOINT(...) tracepoint(libcamera, __VA_ARGS__)

#define LIBCAMERA_TRACEPOINT_IPA_BEGIN(pipe, func) \
tracepoint(libcamera, ipa_call_begin, #pipe, #func)

#define LIBCAMERA_TRACEPOINT_IPA_END(pipe, func) \
tracepoint(libcamera, ipa_call_end, #pipe, #func)

#else

namespace {

template <typename ...Args>
inline void unused([[maybe_unused]] Args&& ...args)
{
}

} /* namespace */

#define LIBCAMERA_TRACEPOINT(category, ...) unused(__VA_ARGS__)

#define LIBCAMERA_TRACEPOINT_IPA_BEGIN(pipe, func)
#define LIBCAMERA_TRACEPOINT_IPA_END(pipe, func)

#endif /* HAVE_TRACING */

#endif /* __LIBCAMERA_INTERNAL_TRACEPOINTS_H__ */


#if HAVE_TRACING

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER libcamera

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "libcamera/internal/tracepoints.h"

#if !defined(INCLUDE_LIBCAMERA_INTERNAL_TRACEPOINTS_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define INCLUDE_LIBCAMERA_INTERNAL_TRACEPOINTS_TP_H

#include <lttng/tracepoint.h>

/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2020, Google Inc.
 *
 * buffer_enums.tp - Tracepoint definition for enums in the buffer class
 */

TRACEPOINT_ENUM(
	libcamera,
	buffer_status,
	TP_ENUM_VALUES(
		ctf_enum_value("FrameSuccess", 0)
		ctf_enum_value("FrameError", 1)
		ctf_enum_value("FrameCancelled", 2)
	)
)


/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2020, Google Inc.
 *
 * request_enums.tp - Tracepoint definition for enums in the request class
 */

TRACEPOINT_ENUM(
	libcamera,
	request_status,
	TP_ENUM_VALUES(
		ctf_enum_value("RequestPending", 0)
		ctf_enum_value("RequestComplete", 1)
		ctf_enum_value("RequestCancelled", 2)
	)
)


/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2020, Google Inc.
 *
 * pipeline.tp - Tracepoints for pipelines
 */

TRACEPOINT_EVENT(
	libcamera,
	ipa_call_begin,
	TP_ARGS(
		const char *, pipe,
		const char *, func
	),
	TP_FIELDS(
		ctf_string(pipeline_name, pipe)
		ctf_string(function_name, func)
	)
)

TRACEPOINT_EVENT(
	libcamera,
	ipa_call_end,
	TP_ARGS(
		const char *, pipe,
		const char *, func
	),
	TP_FIELDS(
		ctf_string(pipeline_name, pipe)
		ctf_string(function_name, func)
	)
)


/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2020, Google Inc.
 *
 * request.tp - Tracepoints for the request object
 */

#include <stdint.h>

#include <libcamera/framebuffer.h>

#include "libcamera/internal/request.h"

TRACEPOINT_EVENT_CLASS(
	libcamera,
	request,
	TP_ARGS(
		libcamera::Request *, req
	),
	TP_FIELDS(
		ctf_integer_hex(uintptr_t, request, reinterpret_cast<uintptr_t>(req))
		ctf_integer(uint64_t, cookie, req->cookie())
		ctf_enum(libcamera, request_status, uint32_t, status, req->status())
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_construct,
	TP_ARGS(
		libcamera::Request *, req
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_destroy,
	TP_ARGS(
		libcamera::Request *, req
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_reuse,
	TP_ARGS(
		libcamera::Request *, req
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_queue,
	TP_ARGS(
		libcamera::Request *, req
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_device_queue,
	TP_ARGS(
		libcamera::Request *, req
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_complete,
	TP_ARGS(
		libcamera::Request::Private *, req
	)
)

TRACEPOINT_EVENT_INSTANCE(
	libcamera,
	request,
	request_cancel,
	TP_ARGS(
		libcamera::Request::Private *, req
	)
)

TRACEPOINT_EVENT(
	libcamera,
	request_complete_buffer,
	TP_ARGS(
		libcamera::Request::Private *, req,
		libcamera::FrameBuffer *, buf
	),
	TP_FIELDS(
		ctf_integer_hex(uintptr_t, request, reinterpret_cast<uintptr_t>(req))
		ctf_integer(uint64_t, cookie, req->_o<libcamera::Request>()->cookie())
		ctf_integer(int, status, req->_o<libcamera::Request>()->status())
		ctf_integer_hex(uintptr_t, buffer, reinterpret_cast<uintptr_t>(buf))
		ctf_enum(libcamera, buffer_status, uint32_t, buf_status, buf->metadata().status)
	)
)




#endif /* INCLUDE_LIBCAMERA_INTERNAL_TRACEPOINTS_TP_H */

#include <lttng/tracepoint-event.h>

#endif /* HAVE_TRACING */