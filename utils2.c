/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:44:20 by maw               #+#    #+#             */
/*   Updated: 2024/12/31 10:12:00 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	countwords_charset(const char *str, char *charset)
{
	size_t	i;
	size_t	count;
	int		in;

	in = 0;
	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (ft_strchr(charset, str[i]) == NULL && in == 0)
		{
			count++;
			in = 1;
		}
		else if (ft_strchr(charset, str[i]) != NULL)
			in = 0;
		i++;
	}
	return (count);
}

void	freesplit_charset(char **tab, size_t number)
{
	while (number > 0)
		free(tab[--number]);
	free(tab);
}

char	**writesplit_charset(const char *s, char **split, char *charset, size_t num)
{
	size_t	start;
	size_t	i;

	i = 0;
	while (s[i])
	{
		while (ft_strchr(charset, s[i]) != NULL && s[i])
			i++;
		start = i;
		while (ft_strchr(charset, s[i]) == NULL && s[i])
			i++;
		if (i > start)
		{
			split[num] = ft_substr(s, start, i - start);
			if (split[num] == NULL)
			{
				freesplit_charset(split, num);
				return (NULL);
			}
			num++;
		}
	}
	split[num] = NULL;
	return (split);
}

char	**ft_split_charset(const char *s, char *charset)
{
	char	**split;
	size_t	num;

	split = malloc((countwords_charset(s, charset) + 1) * sizeof(char *));
	if (split == NULL || s == NULL)
		return (NULL);
	num = 0;
	split = writesplit_charset(s, split, charset, num);
	return (split);
}

// int main (void)
// {
// 	char mot[]= "hello!zzzzzzzz";
// 	// char set = ' ';
// 	char **tab;
// 	int i;

// 	tab = ft_split(mot, 'z');
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }