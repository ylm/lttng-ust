# SPDX-License-Identifier: LGPL-2.1-only

AM_CFLAGS += -fno-strict-aliasing

noinst_LTLIBRARIES = libringbuffer.la

libringbuffer_la_SOURCES = \
	smp.h smp.c getcpu.h \
	shm.c shm.h shm_types.h shm_internal.h \
	ring_buffer_backend.c \
	ring_buffer_frontend.c \
	api.h mmap.h \
	backend.h backend_internal.h backend_types.h \
	frontend_api.h frontend.h frontend_internal.h frontend_types.h \
	nohz.h vatomic.h rb-init.h

libringbuffer_la_LIBADD = \
	-lrt

if HAVE_LIBNUMA
libringbuffer_la_LIBADD += -lnuma
endif

libringbuffer_la_CFLAGS = -DUST_COMPONENT="libringbuffer" $(AM_CFLAGS)
