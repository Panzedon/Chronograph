
					IMPORTANT
					=========

	AS  THE  PROCEDURE  IS  NOT  DONE  AUTOMATICALLY  AFTER  YOU  SENT YOUR REGISTRATION
	INFORMATIONS, IT COULD TAKE A FEW HOURS OR A FEW DAYS (AFTER THE WEEK-END) ACCORDING
	TO YOUR LOCATION AND TIME BEFORE YOU RECEIVE YOUR LICENSE FILE.
	
	THANK YOUR FOR YOUR UNDERSTANDING.

	************************************************************************************

		STM32-32K : Description of the 32K Limitation:

	1) The 32K limitation is applied to all the components allocated to the flash space,
	meaning basically code, constants and datas.

	2) This limited compiler version supports M3/M4 devices only, it does not support
	M0 device, instead of the full version.

	If you try to build some existing projects using the M0 target (option +mod0 set
	either on the compiler command line or in the cxcorm.cxf compiler configuration
	file), you will then have an undefined behavior or an error message:

		"unknow macro +mod0"

	meaning that M0 device is not supported.
