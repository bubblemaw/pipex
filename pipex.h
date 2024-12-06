/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:52:20 by maw               #+#    #+#             */
/*   Updated: 2024/12/06 16:47:14 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "LIBFT/libft.h"
# include <fcntl.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	**cmd_path;
	char	**cmd_arg;
	int		cmd_count;
}	t_pipex;

#endif

