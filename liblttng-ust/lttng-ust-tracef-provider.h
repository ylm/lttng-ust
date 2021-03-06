/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2011-2014 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER lttng_ust_tracef

#if !defined(_TRACEPOINT_LTTNG_UST_TRACEF_PROVIDER_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_LTTNG_UST_TRACEF_PROVIDER_H

#include <lttng/lttng-ust-tracef.h>

#endif /* _TRACEPOINT_LTTNG_UST_TRACEF_PROVIDER_H */

#define TP_IP_PARAM ip	/* IP context received as parameter */
#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./lttng-ust-tracef.h"

/* This part must be outside ifdef protection */
#include <lttng/tracepoint-event.h>
