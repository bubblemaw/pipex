/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:03:09 by masase            #+#    #+#             */
/*   Updated: 2024/12/16 14:45:26 by masase           ###   ########.fr       */
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
    if (!array)
        return;
    int i = 0;
    while (array[i])
    {
        ft_printf(2, "%s\n", array[i]);
        i++;
    }
}

void	free_child(t_pipex *child)
{
	free(child->cmd_path);
	child->cmd_path = NULL;
	free_tab(child->cmd_arg);
}

void	error(const char *str)
{
	ft_printf(2, "zsh: %s: %s\n", strerror(errno), str);
	exit(EXIT_FAILURE);
}