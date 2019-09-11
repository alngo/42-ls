/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:43:56 by alngo             #+#    #+#             */
/*   Updated: 2019/06/04 10:20:14 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(const char *s)
{
	char		*end;

  if (!s)
    return (NULL);
	end = ft_strchr(s, '\0') - 1;
	while (s != end && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	while (s != end && (*end == ' ' || *end == '\n' || *end == '\t'))
		end--;
	if (s == end)
		return (ft_strnew(0));
	else
		return (ft_strsub(s, 0, end - s + 1));
}
