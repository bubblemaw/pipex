/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:03:09 by masase            #+#    #+#             */
/*   Updated: 2024/12/31 13:17:40 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_printf(1, "%s\n", array[i]);
		i++;
	}
}

void	free_data(t_pipex *child)
{
	if (child->cmd_path)
	{
		free(child->cmd_path);
		child->cmd_path = NULL;
	}
	if (child->cmd_arg)
		free_tab(child->cmd_arg);
}

void	error(char *str)
{
	ft_printf(STDERR_FILENO, "zsh: %s: %s\n", strerror(errno), str);
	exit(EXIT_FAILURE);
}

void	error_cmd(const char *str)
{
	ft_printf(STDERR_FILENO, "zsh: command not found: %s\n", str);
	exit(127);
}
