/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:43 by maw               #+#    #+#             */
/*   Updated: 2024/12/19 13:16:07 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	child_process(t_pipex *child, char **av, char **envp, int *fd)
{
	ft_parse(av[2], envp, child);
	child->in_fd = open(av[1], O_RDONLY, 0777);
	if (child->in_fd == -1)
	{
		free_data(child);
		error(av[1]);
	}
	dup2(child->in_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(child->in_fd);
	// print_tab(child->cmd_arg);
	if (execve(child->cmd_path, child->cmd_arg, envp) == -1)
		error("");
}

void	parent_process(t_pipex *child, char **av, char **envp, int *fd)
{
	ft_parse(av[3], envp, child);
	child->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (child->out_fd == -1)
	{
		free_data(child);
		error(av[4]);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(child->out_fd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(child->out_fd);
	// print_tab(child->cmd_arg);
	if (execve(child->cmd_path, child->cmd_arg, envp) == -1)
		error("");
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	t_pipex	child;
	pid_t	pid1;

	if (ac != 5)
		return (0);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
		child_process(&child, av, envp, fd);
	else
		parent_process(&child, av, envp, fd);
	free_data(&child);
	close(fd[0]);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}


int	ft_parse(char *cmd, char **envp, t_pipex *child)
{
	child->cmd_arg = ft_split(cmd, ' ');
	if (child)
	child->cmd_path = ft_cmd_path(envp, child);
	if (child->cmd_path == NULL)
		error("");
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
	// error_cmd(child->cmd_arg[0]);
	return (NULL);
}
