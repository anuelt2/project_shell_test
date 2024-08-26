#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define TOKEN_ARRAY_SIZE 20
#define DELIM " \t\n"

void display_prompt(void);
char *get_input(char *lineptr, size_t len);
char **string_tok(char *str, char *delim);
void execute(char *pathname, char *args[], char *envp[]);

/* str_utils.c */
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int n);
char *_concat(char *var, char *val);
int _strcon(char *str, char c);

/* exec_utils */
char *get_env_path(char **envp, int size);
int _path_size(char **envp);
char *find_command(char *pathname, char **envp);
char *_concatenate(char *dir, char *pathname);
int is_executable(char *full_path);

/* env_utils.c */
int env_size(void);
int env_var_value_len(char **envp, int index);


/* env_functions */
extern char **environ;
void get_env(void);
int set_env(char *var, char *val, int overwrite);

#endif
