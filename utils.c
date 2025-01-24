/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:03:09 by masase            #+#    #+#             */
/*   Updated: 2025/01/24 10:34:47 by maw              ###   ########.fr       */
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

void	error_cmd(char *str)
{
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}
