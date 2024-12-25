# Simple Shell

This project implements a simple Unix shell program that supports reading input, parsing commands, executing those commands, and handling basic built-in commands like `cd` and `env`. The shell prompts the user for input, interprets the commands, and executes them either by forking a new process or using built-in functions.

## Features

- **Command Parsing**: The shell reads user input, tokenizes the string into arguments, and executes the corresponding commands.
- **Command Execution**: The shell uses `execve` to execute commands, searching for them in the directories listed in the `PATH` environment variable.
- **Built-in Commands**: The shell supports basic built-in commands like `cd` (change directory) and `env` (print environment variables).
- **Error Handling**: It provides error messages when a command cannot be found or executed.
- **Prompt**: A custom prompt `($)` is displayed when the shell is running interactively.

## Files

### `shell.h`
The header file that defines the function prototypes and includes necessary libraries. It also defines constants such as `PROMPT` and `MAX_ARGS`.

### `shell.c`
The main file for the shell. It contains the entry point (`main`) and the main loop of the shell. The shell will continuously prompt the user for input, parse it, and execute the command until the `exit` command or EOF (Ctrl+D) is encountered.

### `getline.c`
This file contains the function `read_input()`, which reads a line of input from the user using `getline`.

### `parse.c`
Contains the function `parse_input()` that parses the user input into an array of arguments. It uses `strtok` to split the input by spaces.

### `execute.c`
Contains the function `execute_command()` that handles the execution of commands. It forks a new process and uses `execve` to run the command. It also checks if the command is an absolute path or should be searched for in the `PATH`.

### `builtins.c`
This file contains functions for handling built-in commands. Specifically:
- `handle_cd()` changes the current directory.
- `handle_env()` prints the environment variables.
- `handle_error()` prints an error message when a command cannot be found.

## Usage

To compile and run the shell, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/simple-shell.git
   cd simple-shell
