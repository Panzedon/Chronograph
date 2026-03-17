/*	EXAMPLE PROGRAM WITH INTERRUPT HANDLING
 *	Copyright (c) 2011 by COSMIC Software 
 *
 *	Each character received is copied in a buffer
 *	by the interrupt routine. The main program reads
 *	characters from the buffer and echoes them.
 */
#include <iok60.h>

#define SIZE	512		/* buffer size */
#define TDRE	0x80		/* transmit ready bit */

/*	Authorize interrupts.
 */
#define cli()	_asm("cpsie i")

/*	Some variables.
 */
char buffer[SIZE];		/* reception buffer */
char *ptlec;			/* read pointer */
char * volatile ptecr;		/* write pointer */

/*	Character reception.
 *	Loops until a character is received.
 */
int getch(void)
	{
	int c;				/* character to be returned */

	while (ptlec == ptecr)		/* equal pointers => loop */
		;
	c = *ptlec++;			/* get the received char */
	if (ptlec >= &buffer[SIZE])	/* put in in buffer */
		ptlec = buffer;
	return (c);
	}

/*	Send a char to the SCI A.
 */
void outch(int c)
	{
	while (!(UART0.S1 & TDRE))	/* wait for READY */
		;
	UART0.D = c;			/* send it */
	}

/*	Character reception routine.
 *	This routine is called on interrupt.
 *	It puts the received char in the buffer.
 */
@interrupt void recept(void)
	{
	UART0.S1;			/* clear interrupt */
	*ptecr++ = UART0.D;		/* get the char */
	if (ptecr >= &buffer[SIZE])	/* put it in buffer */
		ptecr = buffer;
	}

/*	Main program.
 *	Sets up the SCI and starts an infinite
 *	loop of receive transmit.
 */
void main(void)
	{
	ptecr = ptlec = buffer;		/* initialize pointers */
	UART0.BDH = 0x27;		/* speed 9600 @96MHz */
	UART0.BDL = 0x10;
	UART0.C2 = 0x2c;		/* enable receive interrupt */
	cli();				/* authorize interrupts */
	for (;;)			/* loop */
		outch(getch());		/* get and put a char */
	}
