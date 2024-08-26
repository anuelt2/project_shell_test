#include "shell.h"

/**
* env_size - get environ size
* Return: length of environ
*/
int env_size(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	;

	return (i);
}

/**
* get_env_size - get environ size
* @env: environment variable size to measure
* Return: length of env list size
*/
int get_env_size(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	;

	return (i);
}

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

/**
* copy_environ - create a copy of environ
* Return: pointer to copy of environ
*/
char **copy_environ(void)
{
	char **environ_copy;
	int i, j, env_var_len, environ_size = env_size();

	environ_copy = malloc(sizeof(char *) * (environ_size + 1));
	if (!environ_copy)
		exit(EXIT_FAILURE);
	environ_copy[environ_size] = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		env_var_len = _strlen(environ[i]);
		environ_copy[i] = malloc(sizeof(char) * (env_var_len + 1));
		if (!environ_copy[i])
			exit(EXIT_FAILURE);
		for (j = 0; environ[i][j] != '\0'; j++)
			environ_copy[i][j] = environ[i][j];
		environ_copy[i][env_var_len] = '\0';
	}
	return (environ_copy);
}
