/*	GENERAL LIMITS HEADER
 *	Copyright (c) 2008 by COSMIC Software
 */
#ifndef __LIMITS__
#define __LIMITS__  1

#define CHAR_BIT    8
#define CHAR_MAX    255
#define CHAR_MIN    0
#define INT_MAX     2147483647
#define INT_MIN   ((long)-2147483648)
#define LONG_MAX    2147483647
#define LONG_MIN  ((long)-2147483648)
#define MB_LEN_MAX  1
#define SCHAR_MAX   127
#define SCHAR_MIN (-128)
#define SHRT_MAX    32767
#define SHRT_MIN  (-32768)
#define UCHAR_MAX   255
#define USHRT_MAX   0xffff
#define UINT_MAX    0xffffffff
#define ULONG_MAX   0xffffffff

#if __LGLG__
#define LLONG_MIN (-9223372036854775808)
#define LLONG_MAX   9223372036854775807
#define ULLONG_MAX  0xffffffffffffffff
#endif

#endif
