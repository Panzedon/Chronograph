/*	STRING TYPES HEADER
 *	Copyright (c) 2011 by COSMIC Software
 */

#ifndef __STRING__
#define __STRING__	1

#ifndef NULL
#define NULL	(void *)0
#endif

#define _BUILTIN @inline

/*	function declarations
 */
char *strcat(char *s1, char *s2);
char *strchr(char *s, int c);
char *strcpy(char *s1, char *s2);
char *strncat(char *s1, char *s2, unsigned int n);
char *strncpy(char *s1, char *s2, unsigned int n);
char *strpbrk(char *s1, char *s2);
char *strrchr(char *s, int c);
char *strstr(char *s1, char *s2);
int memcmp(void *s1, void *s2, unsigned int n);
int strcmp(char *s1, char *s2);
int strncmp(char *s1, char *s2, unsigned int n);
unsigned int strcspn(char *s1, char *s2);
_BUILTIN unsigned int strlen(char *s);
unsigned int strspn(char *s1, char *s2);
void *memchr(void *s, int c, unsigned int n);
void *memcpy(void *s1, void *s2, unsigned int n);
void *memmove(void *s1, void *s2, unsigned int n);
void *memset(void *s, int c, unsigned int n);

#endif
