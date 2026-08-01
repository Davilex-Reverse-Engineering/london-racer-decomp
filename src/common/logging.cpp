#include <windows.h>
#include <cstdio>
#include <cstdarg>

#include "globals.hpp"

// FUNCTION: SPEL 0x004923d0
void log_debug(const char *log_string, ...)
{
  printf("%s\n", log_string);
  FILE *fd;
  char buffer [1023];
  va_list args;

  if (LOG_LEVEL == 0) {
    if (DEBUG_TO_STDOUT == 0) {
      fd = fopen("debug.txt", "at+");
      if (fd != NULL) {
        va_start(args, log_string);
        _snprintf(buffer, 1023, log_string, args);
        va_end(args);
        fprintf(fd, buffer, buffer);
        fclose(fd);
      }
    }
  } else {
    OutputDebugStringA(buffer);
  }
}