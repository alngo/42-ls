/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:43:56 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 15:44:15 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	const char	*us1;
	const char	*us2;

	if (!(*s2))
		return ((char *)s1);
	while ((s1 = ft_strchr(s1, *s2)))
	{
		us1 = s1;
		us2 = s2;
		while (1)
		{
			if (*++us2 == '\0')
				return ((char *)s1);
			else if (*++us1 != *us2)
				break ;
		}
		s1++;
	}
	return (NULL);
}
