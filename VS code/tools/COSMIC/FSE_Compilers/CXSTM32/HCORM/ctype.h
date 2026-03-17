/*	CHARACTER TYPES HEADER
 *	Copyright (c) 2008 by COSMIC Software
 */

#ifndef __CTYPE
#define __CTYPE	1

/*	function declarations
 */
int isalnum(char c);
int isalpha(char c);
int iscntrl(char c);
int isdigit(char c);
int isgraph(char c);
int islower(char c);
int isprint(char c);
int ispunct(char c);
int isspace(char c);
int isupper(char c);
int isxdigit(char c);
int tolower(char c);
int toupper(char c);

/*	macro definitions
 */
#define iscntrl(c) ((c) < ' ' || (c) == 0x7F)
#define isdigit(c) ((c) >= '0' && (c) <= '9')
#define isgraph(c) ((c) > ' ' && (c) < 0x7F)
#define islower(c) ((c) >= 'a' && (c) <= 'z')
#define isprint(c) ((c) >= ' ' && (c) < 0x7F)
#define isspace(c) ((c) == ' ' || ((c) >= '\t' && (c) <= '\r'))
#define isupper(c) ((c) >= 'A' && (c) <= 'Z')

#endif
