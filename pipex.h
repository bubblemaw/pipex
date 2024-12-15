/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:52:20 by maw               #+#    #+#             */
/*   Updated: 2024/12/16 00:02:20 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "LIBFT/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	*cmd_path;
	char	**cmd_arg;
	int		cmd_count;
}	t_pipex;

int		ft_parse(char *cmd, char **envp, t_pipex *child);
char	*ft_cmd_path(char **envp, t_pipex *child);
void	print_tab(char **array);
void	free_tab(char **tab);
void	child_process(t_pipex *child, char **av, char **envp, int *fd);
void	parent_process(t_pipex *child, char **av, char **envp, int *fd);
void	free_child(t_pipex *child);

#endif
