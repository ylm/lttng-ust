# SPDX-License-Identifier: LGPL-2.1-only

AM_CFLAGS += -fno-strict-aliasing

lib_LTLIBRARIES = liblttng-ust-fd.la
liblttng_ust_fd_la_SOURCES = \
	lttng-ust-fd.c

liblttng_ust_fd_la_LIBADD = \
	$(top_builddir)/liblttng-ust/liblttng-ust.la \
	$(DL_LIBS)

liblttng_ust_fd_la_LDFLAGS = -version-info $(LTTNG_UST_LIBRARY_VERSION)
