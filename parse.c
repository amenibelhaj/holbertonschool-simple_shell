#include "main.h"
/**
 * parse_input - Processes a string input.
 * @input: A pointer to the string to be parsed.
 * Description: This function processes the given input string,
 * typically by parsing or manipulating its contents.
 */

void parse_input(char *input)
{
if (strlen(input) > 0)
{
execute_command(input);
}
}
