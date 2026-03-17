/*	MATHEMATICAL FUNCTIONS HEADER
 *	Copyright(c) 2008 by COSMIC Software
 */
#ifndef __MATH__
#define __MATH__	1

#define HUGE_VAL 1E308

double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double y, double x);
double ceil(double x);
double cos(double x);
double cosh(double x);
double exp(double x);
double fabs(double x);
double floor(double x);
double fmod(double x, double y);
double frexp(double x, int *pexp);
double ldexp(double x, int exp);
double log(double x);
double log10(double x);
double modf(double value, double *pd);
double pow(double x, double y);
double sin(double x);
double sinh(double x);
double sqrt(double x);
double tan(double x);
double tanh(double x);

#if __CC99__
#define acosf(x)	acos(x)
#define asinf(x)	asin(x)
#define atanf(x)	atan(x)
#define atan2f(y, x)	atan2(y, x)
#define ceilf(x)	ceil(x)
#define cosf(x)		cos(x)
#define coshf(x)	cosh(x)
#define expf(x)		exp(x)
#define fabsf(x)	fabs(x)
#define floorf(x)	floor(x)
#define fmodf(x, y)	fmod(x, y)
#define frexpf(x, p)	frexp(x, p)
#define ldexpf(x, e)	ldexp(x, e)
#define logf(x)		log(x)
#define log10f(x)	log10(x)
#define modff(v, p)	modf(v, p)
#define powf(x, y)	pow(x, y)
#define sinf(x)		sin(x)
#define sinhf(x)	sinh(x)
#define sqrtf(x)	sqrt(x)
#define tanf(x)		tan(x)
#define tanhf(x)	tanh(x)
#endif

#endif
