#include "shell.h"

static char **environ_copy = '\0';
static int environ_size;
/**
* get_env - print env variables
* Return: void
*/
void get_env(void)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			write(STDOUT_FILENO, &environ[i][j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
* set_env - Initialise new env var or modify an existing one
* @var: variable name to create or modify
* @val: value to give to pass to var
* @overwrite: instruction to overwrite existing variable
* Return: int
*/
int set_env(char *var, char *val, int overwrite)
{

	return (0);
}
