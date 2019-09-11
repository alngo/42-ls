/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:08:02 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:48:27 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			xhandle_pointer(t_arg *arg, char *buf,
		size_t *len, size_t add)
{
	char			tmp[ft_strlen(buf) + add + 2];
	size_t			size;
	size_t			i;

	i = 2;
	tmp[0] = '0';
	tmp[1] = 'x';
	while (i < add)
		tmp[i++] = '0';
	tmp[i] = '\0';
	ft_strcat(tmp, buf);
	size = ft_strlen(tmp);
	push_tmp(tmp, arg, len, size);
}

int					handle_pointer(t_arg *arg, va_list *ap, size_t *len)
{
	char			*buf;
	size_t			add;

	arg->n = (unsigned long)va_arg(*ap, unsigned long);
	if (!(buf = ft_litob(arg->n, arg, 16, "0123456789abcdef")))
		return (0);
	add = 0;
	if (arg->flags & ZE && !(arg->flags & MI) &&
			(ft_strlen(buf) < arg->width) && !(arg->prec))
		add = arg->width - ft_strlen(buf);
	else if (arg->prec)
	{
		if (arg->prec > ft_strlen(buf))
			add = arg->prec - ft_strlen(buf) + 2;
		arg->flags &= ~ZE;
	}
	if (arg->dot && !arg->n)
		buf[0] = '\0';
	xhandle_pointer(arg, buf, len, add);
	free(buf);
	return (1);
}
