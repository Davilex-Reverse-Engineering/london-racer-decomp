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
