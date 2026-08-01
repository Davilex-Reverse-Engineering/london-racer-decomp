#ifndef COMMON_LOGGING_HPP
#define COMMON_LOGGING_HPP

// GLOBAL: SPEL 0x00536aac
int LOG_LEVEL = 0x00;

// GLOBAL: SPEL 0x00536ab0
int DEBUG_TO_STDOUT = 0;

void configure_debug_logging(int debug_log_to_stdout, int log_level);

void  log_debug(const char * log_string, ...);

#endif /* COMMON_GLOBALS_HPP */
