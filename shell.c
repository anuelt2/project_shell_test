#include "shell.h"

/**
* main - Shell program entry point
* @argc: Number of commandline arguments
* @argv: Pointer to array of commandline arguments
* @envp: Pointer to array of environment variables
*
* Return: Always 0 (Success)
*/

int main(int argc, char *argv[], char *envp[])
{
	char input[128];
	char *delim = DELIM;
	char *commands[MAX_COMMANDS], *operators[MAX_COMMANDS];
	int command_count = 0, operator_count = 0, exit_status, cmd_count, i;
	char *str;
	char *pathname;
	char **args;

	(void)argc;
	(void)argv;
	cmd_count = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
			fflush(stdout);
		}
		str = get_input(input, sizeof(input));
		cmd_count++;

		command_tok(str, commands, operators, &command_count, &operator_count);
		while (i < command_count)
		{
			args = string_tok(commands[i], delim);
			pathname = args[0];
			if (args[0] != NULL)
			{
				if (exec_builtin(args, envp) == 0)
					exit_status = exec_external(pathname, args, envp, cmd_count);
				free(str);
				free(args);
			}
			if (i < operator_count)
			{
			if (_strcmp(operators[i], ";") == 0)
			{
				i++;
			}
			else if (_strcmp(operators[i], "&&") == 0)
			{
				if (exit_status == 0)
				{
					i++;
				}
				else
				{
					i += 2;
				}
			}
			else if (_strcmp(operators[i], "||") == 0)
			{
				if (exit_status != 0)
				{
					i++;
				}
				else
				{
					i += 2;
				}
			}
			}
			else
			{
				i++;
			}
		}
	}
	return (0);
}
