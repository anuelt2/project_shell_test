#include "shell.h"

/**
* env_var_value_len - finds the length of an environment variable's value
* @envp: environment list
* @index: index the variable can be found at in environ
* Return: length of the value
*/
int env_var_value_len(char **envp, int index)
{
	int i, j, n = 0;

	for (i = 0; envp[index][i] != '\0'; i++)
	{
		if (envp[index][i] == '=')
			j = i;
	}

	for (i = 0; envp[index][i] != '\0'; i++)
	{
		if (i > j)
			n++;
	}

	return (n);
}
