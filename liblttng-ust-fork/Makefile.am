# SPDX-License-Identifier: LGPL-2.1-only

AM_CFLAGS += -fno-strict-aliasing

lib_LTLIBRARIES = liblttng-ust-fork.la
liblttng_ust_fork_la_SOURCES = ustfork.c
liblttng_ust_fork_la_LIBADD = \
	$(top_builddir)/liblttng-ust/liblttng-ust.la \
	$(DL_LIBS)

liblttng_ust_fork_la_CFLAGS = -DUST_COMPONENT=liblttng-ust-fork $(AM_CFLAGS)

liblttng_ust_fork_la_LDFLAGS = -version-info $(LTTNG_UST_LIBRARY_VERSION)
