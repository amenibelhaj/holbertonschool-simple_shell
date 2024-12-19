#include "main.h"
char **parse_line(char *line)
{
int buffer_size = 64;
int position = 0;
char **args = malloc(buffer_size * sizeof(char *));
char *token;
if (!args)
{
perror("malloc");
exit(EXIT_FAILURE);
    }
token = strtok(line, " \n");
while (token != NULL)
{
args[position] = token;
position++;

if (position >= buffer_size)
{
buffer_size += 64;
args = realloc(args, buffer_size * sizeof(char *));
if (!args)
{
perror("realloc");
exit(EXIT_FAILURE);
}}
token = strtok(NULL, " \n");
}
args[position] = NULL;

return (args);
}
