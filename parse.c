#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * execute_command - Executes a single-word command.
 * @cmd: The command to execute.
 * Description: This function uses execve() to execute the provided command.
 */

void parse_input(char *input)
{
    if (input == NULL || strlen(input) == 0)
        return;

    execute_command(input);
}
