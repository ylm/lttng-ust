/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2013  Mentor Graphics
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER lttng_ust_pthread

#if !defined(_TRACEPOINT_UST_PTHREAD_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_UST_PTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(lttng_ust_pthread, pthread_mutex_lock_req,
	TP_ARGS(pthread_mutex_t *, mutex, void *, ip),
	TP_FIELDS(
		ctf_integer_hex(void *, mutex, mutex)
	)
)

TRACEPOINT_EVENT(lttng_ust_pthread, pthread_mutex_lock_acq,
	TP_ARGS(pthread_mutex_t *, mutex, int, status, void *, ip),
	TP_FIELDS(
		ctf_integer_hex(void *, mutex, mutex)
		ctf_integer(int, status, status)
	)
)

TRACEPOINT_EVENT(lttng_ust_pthread, pthread_mutex_trylock,
	TP_ARGS(pthread_mutex_t *, mutex, int, status, void *, ip),
	TP_FIELDS(
		ctf_integer_hex(void *, mutex, mutex)
		ctf_integer(int, status, status)
	)
)

TRACEPOINT_EVENT(lttng_ust_pthread, pthread_mutex_unlock,
	TP_ARGS(pthread_mutex_t *, mutex, int, status, void *, ip),
	TP_FIELDS(
		ctf_integer_hex(void *, mutex, mutex)
		ctf_integer(int, status, status)
	)
)

#endif /* _TRACEPOINT_UST_PTHREAD_H */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./ust_pthread.h"

/* This part must be outside ifdef protection */
#include <lttng/tracepoint-event.h>

#ifdef __cplusplus
}
#endif
