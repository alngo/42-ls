/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:43:56 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 15:43:51 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	while (s1[i] != '\0'
		&& s2[y] != '\0'
		&& i < n)
	{
		if (s1[i] == s2[y])
			y++;
		else
		{
			i -= y;
			y = 0;
		}
		i++;
	}
	if (s2[y] == '\0')
		return ((char *)(s1 + i - y));
	return (NULL);
}
