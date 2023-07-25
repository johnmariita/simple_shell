#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
void env_func(char **);
void exit_func(char **, char *);
int is_builtin(char **, char **, int, char **, char *);
int _putchar(int c);
void _printf(char *format, ...);
void handle_int(int num);
char **tokenify(char *usr_cmd);
void execute(char **, char *, int, char**);
void handle_sig(int sig);
void remove_new_line(char *buffer);
int _strlen(char *buff);
int _strcmp(char *s1, char *s2);
void _free(int count, ...);
int _atoi(char *);
#endif
