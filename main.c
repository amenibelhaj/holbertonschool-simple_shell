#include "main.h"
/**
 * main - Entry point of the program.
 * Description: This function is the starting point of the program's execution.
 * It typically contains the program's initialization and logic flow.
 * @return: Always returns 0 to indicate successful execution.
 */

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
