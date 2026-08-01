#include <windows.h>
#include <cstdio>
#include <cstdarg>

#include "logging.hpp"

// GLOBAL: SPEL 0x00536aac
int LOG_LEVEL = 0;

// GLOBAL: SPEL 0x00536ab0
int DEBUG_TO_STDOUT = 0;

// FUNCTION: SPEL 0x004923b0
void configure_debug_logging(int debug_log_to_stdout, int log_level)
{
  LOG_LEVEL = log_level;
  DEBUG_TO_STDOUT = debug_log_to_stdout;
}

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