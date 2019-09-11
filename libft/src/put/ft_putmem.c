/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:41:06 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 15:23:47 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_memory_pad(size_t i, char *buf)
{
	size_t		pad;

	pad = i % 16;
	while (i % 16)
	{
		write(1, "  ", 2);
		i++;
		if (!(i % 2) && i)
			write(1, " ", 1);
	}
	write(1, buf, pad);
	if (pad)
		write(1, "\n", 1);
}

static void		fill_buf(char *s, size_t n)
{
	while (n != 1)
	{
		*s = 0;
		s++;
		n--;
	}
	*s = '\n';
}

void			ft_putmem(const void *ptr, size_t n)
{
	unsigned char	*tmp;
	char		*hex;
	char		buf[17];
	size_t		i;

	hex = "0123456789abcdef";
	fill_buf(buf, 17);
	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		write(1, &hex[(*tmp >> 4)], 1);
		write(1, &hex[(*tmp & 0xf)], 1);
		buf[i % 16] = (ft_isprint(*tmp) ? *tmp : '.');
		i++;
		if (!(i % 2) && i)
			write(1, " ", 1);
		if (!(i % 16) && i)
			write(1, buf, 17);
		tmp++;
	}
	print_memory_pad(i, buf);
}
