#include <windows.h>

#include "globals.hpp"
#include "../common/logging.hpp"


// GLOBAL: SPEL 0x005053ec
int running = 0;

// FUNCTION: SPEL 0x0043f9b3
void  start_game() {
    running = 1;
    return;
}

// FUNCTION: SPEL 0x0044815b
void init_main(HINSTANCE hInstance, int nCmdShow) {
    int value;

    // load_raser_ini("raser.ini");
    // value = get_debug_on();
    value = 0;
    if (value == 0) {
        configure_debug_logging(0, 0);
    } else {
        configure_debug_logging(0,1);
    }                           
    // load_texts();
    // set_finished();
    // load_graphics_settings();
    log_debug("Initing 2d skelet\n");
    // init_skele2d(param_1,param_2);
    // value = FUN_0043aa11();
    value = 3;  // Better for now to crash it until render focus is implemented
    if (value == 1) {
    //     init_3d(1,(void *)0xa,(void *)0xa,0x1000);
    } else if (value == 2) {
    //     init_3d(2,(void *)0xa,(void *)0xa,0x1000);
    } else {
        log_fatal("%s(%d) - (init_main) - Illegal renderfocus.\n",
                "D:\\Work\\London Racer\\game\\prog\\Main.cpp",0x85);
    }
    // FUN_00434997();
    log_debug("Initing game\n");
    // FUN_0043e73f();
    log_debug("Initing game timer.\n");
    // FUN_0046b533((int *)&TIMER);
    log_debug("Calling \'handle_progress_bar\'");
    // FUN_00434aa8();
    log_debug("Calling \'end_progress_bar\'");
    // FUN_004349c0();
    log_debug("Calling \'start_framecount_timing\'");
    // FUN_00440280();
    // uVar1 = WINDOW;
    // this = (AutoClass1 *)FUN_00456390();
    // AutoClass1::FUN_0045640b(this,param_1,uVar1);
    // FUN_00416541(&DAT_004cfba8);
    return;
}

// FUNCTION: SPEL 0x00448307
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
    int return_value;

    init_main(hInstance, nCmdShow);
    log_debug("\'init_main\' completed.\n");
    log_debug("Calling \'start_game\'");     
    start_game();          
    log_debug("Entering main loop\n");

    while (running != 0) {                        
        log_debug("Calling \'handle_game\'\n");                  
        log_debug("Calling \'handle_framecount_timing\'\n");                              
        log_debug("Calling \'my_handle_win_msg\'\n");
    }   
    log_debug("Exiting main loop");
    log_debug("Calling \'exit main\'\n");

    return return_value;
}
