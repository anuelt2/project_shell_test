#include "shell.h"

/**
 * string_tok - Calls and implements strtok function
 * @str: Command string
 * @delim: Delimiter string
 *
 * Return: Array of command-line arguments
 */

char **string_tok(char *str, char *delim)
{
	char *token;
	char **args;
	int token_count;
	int array_size;

	delim = DELIM;
	token_count = 0;
	array_size = TOKEN_ARRAY_SIZE;

	args = malloc(sizeof(char *) * array_size);
	if (args == NULL)
	{
		perror("Malloc Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		if (token_count >= array_size)
		{
			array_size *= 2;
			args = realloc(*args, sizeof(char *) * array_size);
			if (args == NULL)
			{
				free(args);
				perror("Realloc Error");
				exit(EXIT_FAILURE);
			}
		}
		args[token_count] = token;
		token_count++;
		token = strtok(NULL, delim);
	}
	args[token_count] = '\0';

	return (args);
}

/**
* command_tok - handle tokenization of full commands
* @str: input string from the command line
* @commands: array to store the tokenized commands in
* @command_count: num of commands
* @operator_count: num of operators
* Return: void
*/
void command_tok(char *str, char *commands[], char *operators[MAX_COMMANDS], int *command_count, int *operator_count)
{
	char *token;
	char *delim_position;

	token = strtok(str, ";|&");
	while (token != NULL)
	{
		commands[*command_count++] = token;

		delim_position = token + _strlen(token);
		if (*delim_position == ';')
		{
			operators[*operator_count++] = ";";
		}
		else if (*delim_position == '&' && *(delim_position + 1) == '&')
		{
			operators[*operator_count++] = "&&";
		}
		else if (*delim_position == '|' && *(delim_position + 1) == '|')
		{
			operators[*operator_count++] = "||";
		}

		token = strtok(NULL, ";|&");
	}
}
