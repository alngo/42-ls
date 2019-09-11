/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:08:11 by alngo             #+#    #+#             */
/*   Updated: 2017/07/25 18:58:07 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		push_tmp(char *tmp, t_arg *arg, size_t *len, size_t size)
{
	char	c;
	size_t	n;
	size_t	p;

	p = size;
	if (arg->prec && (arg->spec == 's' || arg->prec == 'S'))
		p = size < arg->prec ? size : arg->prec;
	c = ((arg->flags & ZE) && !(arg->flags & MI)) ? '0' : ' ';
	n = (arg->width < p) ? 0 : arg->width - p;
	if (n && !(arg->flags & MI))
		pad(c, n, len);
	ft_putnstr_fd(tmp, p, 1);
	if (n && arg->flags & MI)
		pad(c, n, len);
	*len = *len + p;
}

void		pad(char c, size_t n, size_t *len)
{
	if (!(n))
		return ;
	while (n)
	{
		ft_putchar(c);
		*len = *len + 1;
		n--;
	}
}

int			isspec(char c, t_arg *arg)
{
	char	*spec;
	int		i;

	spec = "sSpdDioOuUxXcCbB%";
	i = 0;
	arg->spec = 0;
	while (spec[i])
	{
		if (spec[i] == c)
			return ((arg->spec = spec[i]));
		else if (ft_isupper(c))
			return ((arg->spec = c));
		i++;
	}
	return (0);
}

int			isparsable(char c)
{
	char	*parsable;
	int		i;

	parsable = "#+-. 0123456789hljz*";
	i = 0;
	while (parsable[i])
	{
		if (c == parsable[i])
			return (1);
		i++;
	}
	return (0);
}
