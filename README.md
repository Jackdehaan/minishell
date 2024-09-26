# Pipex

## Description
Pipex is a project that focuses on handling pipes in C. The goal is to recreate the functionality of shell pipes, allowing the execution of commands with input and output redirection.

### Arguments
The program takes 4 arguments:
```
./pipex file1 cmd1 cmd2 file2
```
- `file1` and `file2` are file names.
- `cmd1` and `cmd2` are shell commands with their parameters.

## How to Use
1. Clone the repository
2. Run `make` to compile the project
3. Execute the program with the required arguments


# for example

```bash
./pipex infile "ls -l" "wc -l" outfile
# Should behave like: < infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
# Should behave like: < infile grep a1 | wc -w > outfile
```
