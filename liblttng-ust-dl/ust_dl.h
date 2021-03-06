/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2013 Paul Woegerer <paul_woegerer@mentor.com>
 * Copyright (C) 2015 Antoine Busque <abusque@efficios.com>
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER lttng_ust_dl

#if !defined(_TRACEPOINT_UST_DL_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_UST_DL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#define LTTNG_UST_DL_PROVIDER
#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(lttng_ust_dl, dlopen,
	TP_ARGS(void *, ip, void *, baddr, const char *, path,
		int, flags, uint64_t, memsz, uint8_t, has_build_id,
		uint8_t, has_debug_link),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
		ctf_integer(uint64_t, memsz, memsz)
		ctf_integer_hex(int, flags, flags)
		ctf_string(path, path)
		ctf_integer(uint8_t, has_build_id, has_build_id)
		ctf_integer(uint8_t, has_debug_link, has_debug_link)
	)
)

#ifdef HAVE_DLMOPEN
TRACEPOINT_EVENT(lttng_ust_dl, dlmopen,
	TP_ARGS(void *, ip, void *, baddr, Lmid_t, nsid,
		const char *, path, int, flags,
		uint64_t, memsz, uint8_t, has_build_id,
		uint8_t, has_debug_link),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
		ctf_integer(uint64_t, memsz, memsz)
		ctf_integer(Lmid_t, nsid, nsid)
		ctf_integer_hex(int, flags, flags)
		ctf_string(path, path)
		ctf_integer(uint8_t, has_build_id, has_build_id)
		ctf_integer(uint8_t, has_debug_link, has_debug_link)
	)
)
#endif

TRACEPOINT_EVENT(lttng_ust_dl, build_id,
	TP_ARGS(
		void *, ip,
		void *, baddr,
		uint8_t *, build_id,
		size_t, build_id_len
	),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
		ctf_sequence_hex(uint8_t, build_id, build_id,
			size_t, build_id_len)
	)
)

TRACEPOINT_EVENT(lttng_ust_dl, debug_link,
	TP_ARGS(
		void *, ip,
		void *, baddr,
		char *, filename,
		uint32_t, crc
	),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
		ctf_integer(uint32_t, crc, crc)
		ctf_string(filename, filename)
	)
)

TRACEPOINT_EVENT(lttng_ust_dl, dlclose,
	TP_ARGS(void *, ip, void *, baddr),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
	)
)

#endif /* _TRACEPOINT_UST_DL_H */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./ust_dl.h"

/* This part must be outside ifdef protection */
#include <lttng/tracepoint-event.h>

#ifdef __cplusplus
}
#endif
