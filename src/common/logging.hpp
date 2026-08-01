#ifndef COMMON_LOGGING_HPP
#define COMMON_LOGGING_HPP

void configure_debug_logging(int debug_log_to_stdout, int log_level);

void log_debug(const char * log_string, ...);

void log_fatal(char * log_string, ...);

int drain_message_queue();

#endif /* COMMON_GLOBALS_HPP */
