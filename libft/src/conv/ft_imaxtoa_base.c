/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:37:55 by alngo             #+#    #+#             */
/*   Updated: 2019/09/18 11:40:29 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_imaxtoa_base(intmax_t value, uint8_t base, const char *cipher)
{
	uintmax_t	i;
	intmax_t	size;
	char		*ret;

	i = (value < 0) ? -value : value;
	size = 1 + (value < 0);
	while ((i /= base))
		size++;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	i = (value < 0) ? -value : value;
	ret[--size] = cipher[i % base];
	while ((i /= base))
		ret[--size] = cipher[i % base];
	if (value < 0)
		ret[--size] = '-';
	return (ret);
}
