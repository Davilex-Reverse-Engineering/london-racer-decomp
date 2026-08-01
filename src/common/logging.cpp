#include <windows.h>
#include <cstdio>
#include <cstdarg>

#include "logging.hpp"

// GLOBAL: SPEL 0x00536aac
int LOG_LEVEL = 0;

// GLOBAL: SPEL 0x00536ab0
int DEBUG_TO_STDOUT = 0;

// GLOBAL: SPEL 0x00536a6c
HWND WINDOW;

// FUNCTION: SPEL 0x004923b0
void configure_debug_logging(int debug_log_to_stdout, int log_level)
{
  LOG_LEVEL = log_level;
  DEBUG_TO_STDOUT = debug_log_to_stdout;
}

// FUNCTION: SPEL 0x004923d0
void log_debug(const char *log_string, ...)
{
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

// FUNCTION: SPEL 0x00492580
void log_fatal(char * log_string, ...)
{
  int value;
  char buffer [400];
  va_list args;

  va_start(args, log_string);
  sprintf(buffer, log_string, args);
  va_end(args);

  configure_debug_logging(0,1);                 
  log_debug("[%d] %s\n", 0, buffer);
  ShowWindow(WINDOW, 6);
  value = drain_message_queue();
  while (value != 0) {
    value = drain_message_queue();
  }
  MessageBoxExA(NULL, buffer, NULL, MB_ICONSTOP | MB_SETFOREGROUND, 0);
  ExitProcess(1);
}

// FUNCTION: SPEL 0x0049cf00
int drain_message_queue()
{
  int result;
  tagMSG msg;

  while (BOOL result = PeekMessageA(&msg, NULL, 0, 0, 1)) {
    if (msg.message == 0x12) {
        // There was an check here that I don't understand
        return 1;
    }
    
    TranslateMessage(&msg);
    DispatchMessageA(&msg);
  }
  return 0;
}