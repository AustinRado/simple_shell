# 0x16. C - Simple Shell
## Background
Write a simple UNIX commant interpreter

# Github
*There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.

# More Information
## Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:

`$ echo "qwerty" | /bin/sh`
`/bin/sh: 1: qwerty: not found`
`$ echo "qwerty" | /bin/../bin/sh`
`/bin/../bin/sh: 1: qwerty: not found`
`$`

Same error with your program hsh:

`$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$`

## Compilation
Your shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# Tasks
## 0. Betty would be proud
Write a beautiful code that passes the Betty checks

## 1.Simple shell 0.1
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

1. Display a prompt and wait for the user to type a command. A command line always ends with a new line.
2. The prompt is displayed again each time a command has been executed.
3. The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
4. The command lines are made only of one word. No arguments will be passed to programs.
5. If an executable cannot be found, print an error message and display the prompt again.
6. Handle errors.
7. You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

1. use the PATH
2. implement built-ins
3. handle special characters : ", ', `, , *, &, #
4. be able to move the cursor
5. handle commands with arguments

execve will be the core part of your Shell, don’t forget to pass the environ to it…
