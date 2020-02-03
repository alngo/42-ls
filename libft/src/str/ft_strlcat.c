/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:43:56 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 15:43:18 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		end;

	i = 0;
	end = ft_strnlen(s1, n);
	if (end < n)
	{
		while (s2[i] != '\0'
			&& (end + i) < (n - 1))
		{
			s1[end + i] = s2[i];
			i++;
		}
		s1[end + i] = '\0';
	}
	return (end + ft_strlen(s2));
}
