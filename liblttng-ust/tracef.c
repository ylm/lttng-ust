/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2013-2014 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 */

#define _LGPL_SOURCE
#include <stdio.h>
#include <ust-helper.h>

#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE
#include "lttng-ust-tracef-provider.h"

static inline __attribute__((always_inline))
void __lttng_ust_vtracef(const char *fmt, va_list ap)
{
	char *msg;
	const int len = vasprintf(&msg, fmt, ap);

	/* len does not include the final \0 */
	if (len < 0)
		goto end;
	__tracepoint_cb_lttng_ust_tracef___event(msg, len,
		LTTNG_UST_CALLER_IP());
	free(msg);
end:
	return;
}

void _lttng_ust_vtracef(const char *fmt, va_list ap)
{
	__lttng_ust_vtracef(fmt, ap);
}

void _lttng_ust_tracef(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	__lttng_ust_vtracef(fmt, ap);
	va_end(ap);
}
