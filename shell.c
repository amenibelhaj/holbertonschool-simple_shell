#include "shell.h"
/**
 * main - Main entry point for the shell program.
 * This function runs an infinite loop, prompting the user for input and
 * executing commands based on the user's input.
 * @Return: 0 on successful execution.
 */
int main()
{
char *input;
char **args;

while (1)
{
printf("$ ");
fflush(stdout);
input = read_input();
if (input == NULL)
{
break;
}
args = parse_input(input);
if (args[0] == NULL)
{
free(input);
continue;
}
if (strcmp(args[0], "exit") == 0)
{
handle_exit();
}
else
{
execute_command(args);
}
free(input);
free(args);
}
return (0);
}
