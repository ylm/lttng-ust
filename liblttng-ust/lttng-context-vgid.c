/*
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (C) 2009-2012 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 * Copyright (C) 2019 Michael Jeanson <mjeanson@efficios.com>
 *
 * LTTng UST namespaced real group ID context.
 */

#define _LGPL_SOURCE
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <lttng/ust-events.h>
#include <lttng/ust-tracer.h>
#include <lttng/ringbuffer-config.h>

#include "context-internal.h"
#include "creds.h"


/*
 * At the kernel level, user IDs and group IDs are a per-thread attribute.
 * However, POSIX requires that all threads in a process share the same
 * credentials. The NPTL threading implementation handles the POSIX
 * requirements by providing wrapper functions for the various system calls
 * that change process UIDs and GIDs. These wrapper functions (including those
 * for setreuid() and setregid()) employ a signal-based technique to ensure
 * that when one thread changes credentials, all of the other threads in the
 * process also change their credentials.
 */

/*
 * We cache the result to ensure we don't trigger a system call for
 * each event. User / group IDs are global to the process.
 */
static gid_t cached_vgid = INVALID_GID;

static
gid_t get_vgid(void)
{
	gid_t vgid;

	vgid = CMM_LOAD_SHARED(cached_vgid);

	if (caa_unlikely(cached_vgid == (gid_t) -1)) {
		vgid = getgid();
		CMM_STORE_SHARED(cached_vgid, vgid);
	}

	return vgid;
}

/*
 * The vgid can change on setuid, setreuid and setresuid.
 */
void lttng_context_vgid_reset(void)
{
	CMM_STORE_SHARED(cached_vgid, INVALID_GID);
}

static
size_t vgid_get_size(struct lttng_ctx_field *field, size_t offset)
{
	size_t size = 0;

	size += lib_ring_buffer_align(offset, lttng_alignof(gid_t));
	size += sizeof(gid_t);
	return size;
}

static
void vgid_record(struct lttng_ctx_field *field,
		 struct lttng_ust_lib_ring_buffer_ctx *ctx,
		 struct lttng_channel *chan)
{
	gid_t vgid;

	vgid = get_vgid();
	lib_ring_buffer_align_ctx(ctx, lttng_alignof(vgid));
	chan->ops->event_write(ctx, &vgid, sizeof(vgid));
}

static
void vgid_get_value(struct lttng_ctx_field *field,
		struct lttng_ctx_value *value)
{
	value->u.s64 = get_vgid();
}

int lttng_add_vgid_to_ctx(struct lttng_ctx **ctx)
{
	struct lttng_ctx_field *field;

	field = lttng_append_context(ctx);
	if (!field)
		return -ENOMEM;
	if (lttng_find_context(*ctx, "vgid")) {
		lttng_remove_context_field(ctx, field);
		return -EEXIST;
	}
	field->event_field.name = "vgid";
	field->event_field.type.atype = atype_integer;
	field->event_field.type.u.integer.size = sizeof(gid_t) * CHAR_BIT;
	field->event_field.type.u.integer.alignment = lttng_alignof(gid_t) * CHAR_BIT;
	field->event_field.type.u.integer.signedness = lttng_is_signed_type(gid_t);
	field->event_field.type.u.integer.reverse_byte_order = 0;
	field->event_field.type.u.integer.base = 10;
	field->event_field.type.u.integer.encoding = lttng_encode_none;
	field->get_size = vgid_get_size;
	field->record = vgid_record;
	field->get_value = vgid_get_value;
	lttng_context_update(*ctx);
	return 0;
}
