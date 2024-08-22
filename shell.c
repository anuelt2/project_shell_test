#include "shell.h"

/**
 * main - Shell program entry point
 * @argc: Number of commandline arguments
 * @argv: Pointer to array of commandline arguments
 * @envp: Pointer to array of environment variables
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char **envp)
{
	char input[128];
	char *delim = DELIM;
	char *str;
	char *full_path;
	char **args;
	(void)argc;
	(void)argv;

	full_path = malloc(sizeof(char) * 4096);
	full_path[4095] = '\0';
	while (1)
	{
		display_prompt();
		str = get_input(input, sizeof(input));
		args = string_tok(str, delim);
		full_path = find_command(args[0], envp);
		printf("full_path passed to main: %s\n", full_path);
		execute(full_path, args, envp);
	}
	free(input);
	free(full_path);

	return (0);
}
