/*	STANDARD I/O HEADER
 *	Copyright (c) 2011 by COSMIC Software
 */

#ifndef __STDIO__
#define __STDIO__	1

#ifndef __SIZE_T__
#define __SIZE_T__	1
typedef unsigned int size_t;
#endif

/*	function declarations
 */
int getchar(void);
char *gets(char *s);
int printf(char *format, ...);
int putchar(char c);
int puts(char *s);
int scanf(char *format, ...);
int sprintf(char *s, char *format, ...);
int sscanf(char *s, char *format, ...);

/*	system parameters
 */
#ifndef BUFSIZ
#define BUFSIZ 	512
#endif

#ifndef EOF
#define EOF	(-1)
#endif

#ifndef NULL
#define NULL	(void *)0
#endif

#endif
