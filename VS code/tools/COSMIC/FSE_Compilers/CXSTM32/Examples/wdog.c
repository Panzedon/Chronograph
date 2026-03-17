#include "iok60.h"
       
void wdog_disable(void)
	{
	WDOG.UNLOCK = 0xC520;	/* unlock WDOG */
	WDOG.UNLOCK = 0xD928;
	WDOG.STCTRLH = 0xd2;	/* WDOGEN = 0 */
	}
