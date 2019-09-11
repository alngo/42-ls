/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:55:52 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 11:56:09 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**alloc_tab(char const *s, char c)
{
	size_t		word_count;
	char		**tab;
	int			i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	tab = (char**)malloc(sizeof(char*) * (word_count + 1));
	return (tab);
}

static char		**ft_strsplit_free(char **tab)
{
	int			tab_i;

	tab_i = 0;
	if (tab)
	{
		while (tab[tab_i])
		{
			if (tab[tab_i])
				free(tab[tab_i++]);
		}
		free(tab);
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		tab_i;
	size_t		i;

	if (!s || !(tab = alloc_tab(s, c)))
		return (NULL);
	tab_i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i == 0)
			break ;
		tab[tab_i] = ft_strsub(s, 0, i);
		if (!tab[tab_i])
			return (ft_strsplit_free(tab));
		tab_i++;
		s += i;
	}
	tab[tab_i] = NULL;
	return (tab);
}
