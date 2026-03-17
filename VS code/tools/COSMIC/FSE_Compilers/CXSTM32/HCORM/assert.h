/*	PROGRAM ASSERTION HEADER
 *	Copyright (c) 2008 by COSMIC Software
 */
#undef assert
#ifndef NDEBUG
#define assert(expr) \
	( \
	(!(expr)) ? \
		( \
		printf("\nassert error at %s:%d\n", \
			__FILE__, __LINE__), \
		exit(0) \
		) : 0 \
	)
#else
#define assert(expr)
#endif
