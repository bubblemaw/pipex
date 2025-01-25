/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:43 by maw               #+#    #+#             */
/*   Updated: 2025/01/25 12:44:17 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *child, char **av, char **envp, int *fd)
{
	child->in_fd = open(av[1], O_RDONLY, 0777);
	if (child->in_fd == -1)
		error(av[1]);
	ft_parse(av[2], envp, child);
	dup2(child->in_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(child->in_fd);
	if (execve(child->cmd_path, child->cmd_arg, envp) == -1)
		error("");
}

void	parent_process(t_pipex *child, char **av, char **envp, int *fd)
{
	child->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (child->out_fd == -1)
		error(av[4]);
	ft_parse(av[3], envp, child);
	dup2(fd[0], STDIN_FILENO);
	dup2(child->out_fd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(child->out_fd);
	if (execve(child->cmd_path, child->cmd_arg, envp) == -1)
		error("");
}

int	piper(char **envp, t_pipex *child, char **av, int *fd)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	status1 = 0;
	status2 = 0;
	pid1 = fork();
	if (pid1 == -1)
		return (0);
	if (pid1 == 0)
		child_process(child, av, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		return (0);
	if (pid2 == 0)
		parent_process(child, av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (status1 != 0 || status2 != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	t_pipex	child;

	if (ac != 5)
		return (0);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	if (piper(envp, &child, av, fd) == 0)
		exit(EXIT_FAILURE);
	return (0);
}
