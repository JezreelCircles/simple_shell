#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>

int token_input(char input[], char **args, char *program, char *line, int st);
int child_process(char **args, char *line);
int handle_path(char *input, char **args, char *program, char *line, int st);
int error_handle(char *path_copy, char *program, char *input, char **args);
int terminate(char **args, char *path, char *line, char *program);
int active(char **args, char *line, int status, int handle);
void Memory(char **args, char **line);
int Process(char *tken, int handle, char **args, char *cd, char *line);
void inter_active_mode(char *program);
void other_error(char **args, char *p);
void exit_status(int number, char *program);
void read_exit_status(char **args);
void nonInteractive(char *program);
void printnum(int n);
int _putchar(char c);
void _puts(char *str);
int main(int argc, char **argv);
void nonInteractive(char *arg);
void inter_active_mode(char *arg);
char *strtok(char *str, const char *delimiters);
int _getline(char **ptr, int *n, FILE *stream);
void _getenv(void);
int is_empty_spaces(char *strs);
int AllDigits(char *s);
void commentAfterhash(char str[]);



#endif
