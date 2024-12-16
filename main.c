/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:43 by maw               #+#    #+#             */
/*   Updated: 2024/12/16 13:53:50 by masase           ###   ########.fr       */
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
		error(av[1]);
		free_child(child);
		return ;
	}
	dup2(child->in_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(child->cmd_path, child->cmd_arg, NULL);
}

void	parent_process(t_pipex *child, char **av, char **envp, int *fd)
{
	ft_parse(av[3], envp, child);
	child->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (child->out_fd == -1)
	{
		error(av[4]);
		free_child(child);
		return ;
	}
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
	free_child(&child);
	close(fd[0]);
	close(fd[1]);

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
