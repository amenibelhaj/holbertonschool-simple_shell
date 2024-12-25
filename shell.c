#include "shell.h"
/**
 * main - Entry point for the shell program
 * @argc: Argument count (not used)
 * @argv: Argument vector (array of command line arguments)
 * @env: Environment variables for the shell
 *
 * Return: 0 on success, exits on EOF (Ctrl+D)
 */
int main(int argc, char **argv, char **env)
{
char *line = NULL, **args;
size_t len = 0;
ssize_t nread;
(void)argc;
(void)argv;
while (1)
{
if (isatty(STDIN_FILENO))
printf("%s", PROMPT);
nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
exit(0);
}
if (line[nread - 1] == '\n')
line[nread - 1] = '\0';
args = parse_input(line);
if (args && args[0])
{
if (strcmp(args[0], "exit") == 0)
{
exit_shell();
exit(0);
}
execute_command(args, env);
}
free(args);
}
free(line);
return (0);
}
