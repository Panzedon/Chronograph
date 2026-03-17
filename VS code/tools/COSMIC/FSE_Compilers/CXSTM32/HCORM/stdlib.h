/*	GENERAL LIBRARY FUNCTIONS HEADER
 *	Copyright (c) 2011 by COSMIC Software
 */
#ifndef __STDLIB__
#define __STDLIB__	1

#define EXIT_FAILURE 0
#define EXIT_SUCCESS 1
#define MB_CUR_MAX 1
#define RAND_MAX 32767

#ifndef NULL
#define NULL	(void *)0
#endif

#ifndef __SIZE_T__
#define __SIZE_T__	1
typedef unsigned int size_t;
#endif

#ifndef __WCHAR_T__
#define __WCHAR_T__	1
typedef char wchar_t;
#endif

typedef struct {
	int quot;
	int rem;
	} div_t;

typedef struct {
	long quot;
	long rem;
	} ldiv_t;

int abs(int i);
double atof(char *nptr);
int atoi(char *nptr);
long atol(char *nptr);
void *calloc(unsigned int nelem, unsigned int elsize);
div_t div(int numer, int denom);
void exit(int status);
void free(void *ptr);
long labs(long l);
ldiv_t ldiv(long numer, long denom);
void *malloc(unsigned int size);
int rand(void);
void *realloc(void *ptr, unsigned int size);
void srand(unsigned int seed);
double strtod(char *s, char **endptr);
long strtol(char *s, char **endptr, int base);

unsigned int isqrt(unsigned int);
unsigned long lsqrt(unsigned long);

#define abort exit
#define strtoul strtol
#define min(a, b)	((a) < (b) ? (a) : (b))
#define max(a, b)	((a) > (b) ? (a) : (b))

#if __LGLG__
typedef struct {
        long long quot;
        long long rem;
        } lldiv_t;
 
#ifdef NOBUILTIN
long long llabs(long long l);
#else
#define llabs(a)        ((a) < 0 ? -(a) : (a))
#endif
 
long long atoll(char *nptr);
lldiv_t lldiv(long long numer, long long denom);
long long strtoll(char *s, char **endptr, int base);
unsigned long long llsqrt(unsigned long long);
 
#define strtoull strtoll
#endif
 
#endif
