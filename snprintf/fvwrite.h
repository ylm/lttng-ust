/*	$OpenBSD: fvwrite.h,v 1.5 2003/06/02 20:18:37 millert Exp $	*/

/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (C) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 */

/*
 * I/O descriptors for __sfvwrite().
 */
#include <stddef.h>

#include "ust-helper.h"

struct __lttng_ust_siov {
	void	*iov_base;
	size_t	iov_len;
};
struct __lttng_ust_suio {
	struct	__lttng_ust_siov *uio_iov;
	int	uio_iovcnt;
	int	uio_resid;
};

LTTNG_HIDDEN
extern int __sfvwrite(LTTNG_UST_LFILE *, struct __lttng_ust_suio *);
