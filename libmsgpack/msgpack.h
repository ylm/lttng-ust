/*
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (C) 2020 Francis Deslauriers <francis.deslauriers@efficios.com>
 */

#ifndef _LTTNG_UST_MSGPACK_H
#define _LTTNG_UST_MSGPACK_H

#include <stddef.h>
#ifdef __KERNEL__
#include <linux/types.h>
#else /* __KERNEL__ */
#include <stdint.h>
#include "ust-helper.h"
#endif /* __KERNEL__ */

struct lttng_msgpack_writer {
	uint8_t *buffer;
	uint8_t *write_pos;
	const uint8_t *end_write_pos;
	uint8_t array_nesting;
	uint8_t map_nesting;
};

LTTNG_HIDDEN
void lttng_msgpack_writer_init(
		struct lttng_msgpack_writer *writer,
		uint8_t *buffer, size_t size);

LTTNG_HIDDEN
void lttng_msgpack_writer_fini(struct lttng_msgpack_writer *writer);

LTTNG_HIDDEN
int lttng_msgpack_write_nil(struct lttng_msgpack_writer *writer);
LTTNG_HIDDEN
int lttng_msgpack_write_true(struct lttng_msgpack_writer *writer);
LTTNG_HIDDEN
int lttng_msgpack_write_false(struct lttng_msgpack_writer *writer);
LTTNG_HIDDEN
int lttng_msgpack_write_unsigned_integer(
		struct lttng_msgpack_writer *writer, uint64_t value);
LTTNG_HIDDEN
int lttng_msgpack_write_signed_integer(
		struct lttng_msgpack_writer *writer, int64_t value);
LTTNG_HIDDEN
int lttng_msgpack_write_double(struct lttng_msgpack_writer *writer, double value);
LTTNG_HIDDEN
int lttng_msgpack_write_str(struct lttng_msgpack_writer *writer,
		const char *value);
LTTNG_HIDDEN
int lttng_msgpack_begin_map(struct lttng_msgpack_writer *writer, size_t count);
LTTNG_HIDDEN
int lttng_msgpack_end_map(struct lttng_msgpack_writer *writer);
LTTNG_HIDDEN
int lttng_msgpack_begin_array(
		struct lttng_msgpack_writer *writer, size_t count);
LTTNG_HIDDEN
int lttng_msgpack_end_array(struct lttng_msgpack_writer *writer);

#endif /* _LTTNG_UST_MSGPACK_H */
