/*	VARIABLE ARGUMENT LIST HEADER
 *	Copyright (c) 2011 by COSMIC Software
 */

#ifndef __STDARG__
#define __STDARG__	1

/*	type and macro declarations
 */
typedef char *va_list;

#define _argsize(ap, ty)	sizeof((*(ty (*)())(ap))())

/*	macros
 */
#define va_start(ap, arg) ((ap) = (char *)&(arg) + sizeof(arg))
#define va_arg(ap, type) ((ap) += _argsize(ap, type), *(type *)((ap) - sizeof(type)))
#define va_end(ap) ap
#define va_copy(apd, aps) ((apd) = (aps))

/*	io functions using va_list
 */
int vprintf(char *format, va_list ap);
int vsprintf(char *s, char *format, va_list ap);

#endif
