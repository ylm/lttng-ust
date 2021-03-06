/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Copyright (C) 2009 Pierre-Marc Fournier
 */

#ifndef UST_SNPRINTF
#define UST_SNPRINTF

#include <stdarg.h>
#include <stddef.h>

#include "ust-helper.h"

LTTNG_HIDDEN
int ust_safe_vsnprintf(char *str, size_t n, const char *fmt, va_list ap);
LTTNG_HIDDEN
int ust_safe_snprintf(char *str, size_t n, const char *fmt, ...)
	__attribute__ ((format (printf, 3, 4)));

#endif /* UST_SNPRINTF */
