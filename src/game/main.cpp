#include "main_SPEL.hpp"

#include <windows.h>

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
    start_game();

    while (running != 0) {

    }

    return return_value;
}
