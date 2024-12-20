#include "main.h"

int main()
{
char *input;
while (1)
{
printf("$ ");
fflush(stdout);

input = get_line();
if (strcmp(input, "exit") == 0)
{
free(input);
exit(0);
}
parse_input(input);
free(input);
}
return (0);
}
