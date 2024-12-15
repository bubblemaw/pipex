/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:43 by maw               #+#    #+#             */
/*   Updated: 2024/12/15 11:39:02 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	print_tab(char **array)
{
    if (!array)
        return;
    int i = 0;
    while (array[i])
    {
        printf("%s\n", array[i]);
        i++;
    }
}

void	child_process(t_pipex *child, char **av, char **envp, int *fd)
{
	ft_parse(av[2], envp, child);
	printf("%s\n", child->cmd_path);
	print_tab(child->cmd_arg);
	child->in_fd = open(av[1], O_RDONLY, 0777);
	dup2(child->in_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(child->cmd_path, child->cmd_arg, NULL);
}

void	parent_process(t_pipex *child, char **av, char **envp, int *fd)
{
	ft_parse(av[3], envp, child);
	printf("%s\n", child->cmd_path);
	print_tab(child->cmd_arg);
	child->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], STDIN_FILENO);
	dup2(child->out_fd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(child->cmd_path, child->cmd_arg, NULL);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	t_pipex	child;
	pid_t	pid1;

	if (ac != 5)
		return (0);
	if (pipe(fd) == -1)
		return (2);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0)
		child_process(&child, av, envp, fd);
	else
		parent_process(&child, av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	free(child.cmd_path);
	child.cmd_path = NULL;
	free_tab(child.cmd_arg);
	return (0);
}

int	ft_parse(char *cmd, char **envp, t_pipex *child)
{
	child->cmd_arg = ft_split(cmd, ' ');
	child->cmd_path = ft_cmd_path(envp, child);
	return (1);
}

char	*ft_cmd_path(char **envp, t_pipex *child)
{
	char	**tab_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	tab_path = ft_split(envp[i] + 5, ':');
	if (tab_path == NULL)
		return (0);
	i = 0;
	while (tab_path[i])
	{
		path = ft_strjoin(tab_path[i], "/");
		path = ft_strjoin(path, child->cmd_arg[0]);
		if (access(path, F_OK) == 0)
		{
			free_tab(tab_path);
			return (path);
		}
		free(path);
		path = NULL;
		i++;
	}
	return (NULL);
}
// #include <sys/types.h>
// #include <unistd.h>
// #include <stdio.h>

// int main() {
//     pid_t pid;

//     pid = fork(); // Fork creates a new process

//     if (pid == -1) {
//         perror("fork failed");
//         return 1;
//     }

//     if (pid == 0) {
//         // Child process
//         printf("I am the child process. My PID is %d\n", getpid());
//     } else {
//         // Parent process
//         printf("I am the parent process. My PID is %d, and my child's PID is %d\n", getpid(), pid);
//     }

//     return 0;
// }
