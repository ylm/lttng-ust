/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2011 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 */

#undef ctf_integer_nowrite
#define ctf_integer_nowrite(_type, _item, _src)			\
	_ctf_integer_ext(_type, _item, _src, BYTE_ORDER, 10, 1)

#undef ctf_float_nowrite
#define ctf_float_nowrite(_type, _item, _src)			\
	_ctf_float(_type, _item, _src, 1)

#undef ctf_array_nowrite
#define ctf_array_nowrite(_type, _item, _src, _length)		\
	_ctf_array_encoded(_type, _item, _src, BYTE_ORDER, _length, none, 1, 10)

#undef ctf_array_nowrite_hex
#define ctf_array_nowrite_hex(_type, _item, _src, _length)	\
	_ctf_array_encoded(_type, _item, _src, BYTE_ORDER, _length, none, 1, 16)

#undef ctf_array_network_nowrite
#define ctf_array_network_nowrite(_type, _item, _src, _length)	\
	_ctf_array_encoded(_type, _item, _src, BIG_ENDIAN,	\
			_length, none, 1, 10)

#undef ctf_array_network_nowrite_hex
#define ctf_array_network_nowrite_hex(_type, _item, _src, _length) \
	_ctf_array_encoded(_type, _item, _src, BIG_ENDIAN,	\
			_length, none, 1, 16)

#undef ctf_array_text_nowrite
#define ctf_array_text_nowrite(_type, _item, _src, _length)	\
	_ctf_array_encoded(_type, _item, _src, BYTE_ORDER, _length, UTF8, 1, 10)

#undef ctf_sequence_nowrite
#define ctf_sequence_nowrite(_type, _item, _src, _length_type, _src_length) \
	_ctf_sequence_encoded(_type, _item, _src, BYTE_ORDER,	\
			_length_type, _src_length, none, 1, 10)

#undef ctf_sequence_nowrite_hex
#define ctf_sequence_nowrite_hex(_type, _item, _src, _length_type, _src_length) \
	_ctf_sequence_encoded(_type, _item, _src, BYTE_ORDER,	\
			_length_type, _src_length, none, 1, 16)

#undef ctf_sequence_network_nowrite
#define ctf_sequence_network_nowrite(_type, _item, _src, _length_type, _src_length) \
	_ctf_sequence_encoded(_type, _item, _src, BIG_ENDIAN,	\
			_length_type, _src_length, none, 1, 10)

#undef ctf_sequence_network_nowrite_hex
#define ctf_sequence_network_nowrite_hex(_type, _item, _src, _length_type, _src_length) \
	_ctf_sequence_encoded(_type, _item, _src, BIG_ENDIAN,	\
			_length_type, _src_length, none, 1, 16)

#undef ctf_sequence_text_nowrite
#define ctf_sequence_text_nowrite(_type, _item, _src, _length_type, _src_length) \
	_ctf_sequence_encoded(_type, _item, _src, BYTE_ORDER,	\
			_length_type, _src_length, UTF8, 1, 10)

#undef ctf_string_nowrite
#define ctf_string_nowrite(_item, _src)				\
	_ctf_string(_item, _src, 1)

#undef ctf_enum_nowrite
#define ctf_enum_nowrite(_provider, _name, _type, _item, _src)		\
	_ctf_enum(_provider, _name, _type, _item, _src, 1)
