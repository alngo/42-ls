/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:49:16 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 11:49:17 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	uintmax_t	i;
	size_t		size;
	char		*ret;

	i = value;
	size = 1;
	while ((i /= base))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = value;
	ret[--size] = str[i % base];
	while ((i /= base))
		ret[--size] = str[i % base];
	return (ret);
}
