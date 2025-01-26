/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:44:20 by maw               #+#    #+#             */
/*   Updated: 2025/01/26 01:28:24 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_parse(char *cmd, char **envp, t_pipex *child)
{
	char	c;

	c = ' ';
	if (ft_strnstr(cmd, "bin", 4) != NULL)
		child->cmd_arg = ft_split(cmd + 5, c);
	else
		child->cmd_arg = ft_split(cmd, c);
	child->cmd_path = ft_cmd_path(envp, child);
	if (child->cmd_path == NULL)
	{
		error_cmd(child->cmd_arg[0]);
		free_tab(child->cmd_arg);
		child->cmd_arg = NULL;
		exit(EXIT_SUCCESS);
	}
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
		return (NULL);
	path = join_path(tab_path, child);
	if (path == NULL)
		return (NULL);
	return (path);
}

char	*join_path(char **tab_path, t_pipex *child)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (tab_path[i])
	{
		tmp = ft_strjoin(tab_path[i], "/");
		path = ft_strjoin(tmp, child->cmd_arg[0]);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_tab(tab_path);
			return (path);
		}
		free(path);
		path = NULL;
		i++;
	}
	free_tab(tab_path);
	return (NULL);
}
