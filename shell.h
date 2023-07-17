#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 20
#define MAX_WORDS 100
int _putchar(int c);
void _printf(char *format, ...);
void handle_int(int num);
char **tokenify(char *usr_cmd);
void execute(char **, char *, int);
void handle_sig(int sig);
void remove_new_line(char *buffer);
#endif
