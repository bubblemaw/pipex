/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:11:44 by maw               #+#    #+#             */
/*   Updated: 2024/12/01 15:18:58 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// void	ft_free_content(void *content)
// {
//     free(content);
// }

// int	main(void)
// {
//     t_list	*node = ft_lstnew(malloc(10));
// Création d'un nœud avec du contenu dynamique

//     ft_lstdelone(node, ft_free_content); 
// Suppression du nœud avec ft_lstdelone
//     return (0);
// }
