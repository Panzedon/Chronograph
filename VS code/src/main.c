#include "tm1637.h"
#include "buttons.h"
#include "chrono.h" 
#include "app.h"
#include "timer.h"


void main(void) {

    Sys_Init();
    Enable_Interrupt();

    ShowMode_HI(); 

    Delay_ms_Safe(1000); 
    Memory_Poll();
    TM1637_Clear();

    App_Run();

}