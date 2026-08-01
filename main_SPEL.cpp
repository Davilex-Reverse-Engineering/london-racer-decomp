#include "main_SPEL.hpp"

// FUNCTION: SPEL 0x10000000
SomeClass::~SomeClass() {
}

// GLOBAL: SPEL 0x10102000
// STRING: SPEL 0x10101f00
const char* g_globalString = "A global string";

#ifdef _WIN32
#include <windows.h>

// FUNCTION: SPEL 0x10000020
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
    return 0;
}
#else
// FUNCTION: SPEL 0x10000020
int main(int argc, char *argv[]) {
    return 0;
}
#endif
