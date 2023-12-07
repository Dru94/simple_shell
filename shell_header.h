#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define NEWLINE_TRIGGER -2

extern char **environ;

#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* compare.c */
int custom_string_compare(const char *str1, const char *str2);

/* custom_get_line.c */
ssize_t custom_get_line(char **lineptr, size_t *n, int fd);

/* custom_str_tokenise.c */
char *custom_chr_search(const char *str, int c);
char *custom_str_tokenise(char *str, const char *delim);

/* env_management.c */
int set_environment(char **arg_array);
int unset_environment(char **arg_array);
int custom_set_environment(const char *name, const char *value);
int custom_unset_enviroment(const char *name);

/* env_management2.c */
void print_environment(void);
void print_env(char **arg_array);

/* handle_error.c */
void handle_exit(int signal);
void handle_exit_failure(char **arg_array, char *name);
void handle_exit_success(char **arg_array, char *name);

/* memory_move.c */
void *memory_move(void *dest, const void *src, size_t n);

/* path_management.c */
void path_concat(char **arg_array, char *abs_path, char *name);
char *get_path_value(void);

/* process_id.c */
void process_id(int argc, char *command, char *name);
void child_pid(int argc, char *command, pid_t parent_pid, char *name);

/* string_copy.c */
void custom_string_copy(char *destination, const char *src);

/* string_len.c */
int custom_string_length(const char *s);

char *custom_str_duplicate(const char *str);
void exit_call(char **arg_array, pid_t parent_pid);

#endif

