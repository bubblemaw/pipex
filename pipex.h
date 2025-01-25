/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:52:20 by maw               #+#    #+#             */
/*   Updated: 2025/01/25 01:02:24 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "FT_PRINTF/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/wait.h>

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
void	free_data(t_pipex *child);
void	error(char *str);
void	error_cmd(char *str);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *small, size_t len);
char	*join_path(char **tab_path, t_pipex *child);
int		piper(char **envp, t_pipex *child, char **av, int *fd);

#endif
