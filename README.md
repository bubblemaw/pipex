*This project has been created as part of the 42 curriculum by masase*

# pipex

## Description

`pipex` reproduces the behavior of the shell pipe mechanism. It discovers how **processes, pipes and file descriptors** work in UNIX: `fork`, `pipe`, `dup2`, `execve`, `wait`.

```bash
./pipex file1 cmd1 cmd2 file2
```

is equivalent to:

```bash
< file1 cmd1 | cmd2 > file2
```

Example:

```bash
./pipex infile "grep hello" "wc -l" outfile
# same as: < infile grep hello | wc -l > outfile
```

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./pipex infile "ls -l" "wc -l" outfile
```

## How it works

1. Parse `PATH` from `envp` and locate each command's executable.
2. Create a pipe with `pipe()`.
3. `fork()` one child per command.
4. In each child: redirect stdin/stdout with `dup2()`, close unused ends, run `execve()`.
5. The parent closes the pipe and waits for the children with `waitpid()`.

Errors (missing file, command not found, permission denied) are reported like the shell would.

## Resources

- `man 2 pipe`, `man 2 fork`, `man 2 dup2`, `man 2 execve`, `man 2 waitpid`
