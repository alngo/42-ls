/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:43:56 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 11:54:11 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int			i;
	char		*ret;

	if (!f)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
