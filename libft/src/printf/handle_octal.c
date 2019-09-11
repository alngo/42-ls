/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:51:16 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:38:35 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*format_octal(t_arg *arg, char *buf, size_t size)
{
	char		*tmp;
	size_t		add;
	size_t		i;

	i = 0;
	add = (arg->flags & SH) ? 1 : 0;
	add += ((arg->prec > size) ? (arg->prec - size) : 0) -
		((arg->prec > size && arg->flags & SH) ? 1 : 0);
	if (arg->flags & ZE && (arg->width > size) && !(arg->prec) &&
			!(arg->flags & MI))
		add += (arg->width - size) - ((arg->flags & PL) ? 1 : 0);
	if (!(tmp = ft_strnew(size + add)))
		return (NULL);
	while (i < add)
		tmp[i++] = '0';
	while (*buf)
		tmp[i++] = *(buf++);
	tmp[i] = '\0';
	return (tmp);
}

static int		handle_big_o(t_arg *arg, size_t *len)
{
	char		*buf;
	char		*tmp;
	size_t		size;

	if (!(buf = ft_litob(arg->n, arg, 8, "0123456789abcdef")))
		return (0);
	if (arg->dot && !(arg->n))
		buf[0] = '\0';
	if (arg->flags & SH && !(arg->dot) && !arg->n)
		arg->flags &= ~SH;
	if (!(tmp = format_octal(arg, buf, ft_strlen(buf))))
		return (0);
	size = ft_strlen(tmp);
	if (arg->prec)
		arg->flags &= ~ZE;
	push_tmp(tmp, arg, len, size);
	free(tmp);
	free(buf);
	return (1);
}

static int		handle_mini_o(t_arg *arg, size_t *len)
{
	char		*buf;
	char		*tmp;
	size_t		size;

	if (arg->type == TY_HH)
		arg->n = (unsigned char)arg->n;
	if (arg->type == TY_H)
		arg->n = (unsigned short)arg->n;
	if (!(buf = ft_litob(arg->n, arg, 8, "0123456789abcdef")))
		return (0);
	if (arg->dot && !(arg->n))
		buf[0] = '\0';
	if (arg->flags & SH && !(arg->dot) && !arg->n)
		arg->flags &= ~SH;
	if (!(tmp = format_octal(arg, buf, ft_strlen(buf))))
		return (0);
	size = ft_strlen(tmp);
	if (arg->prec)
		arg->flags &= ~ZE;
	push_tmp(tmp, arg, len, size);
	free(tmp);
	free(buf);
	return (1);
}

int				handle_octal(t_arg *arg, va_list *ap, size_t *len)
{
	if (arg->spec == 'o' && arg->type != TY_L &&
			arg->type != TY_LL && arg->type != TY_J && arg->type != TY_Z)
	{
		arg->n = (unsigned int)va_arg(*ap, unsigned int);
		if (!(handle_mini_o(arg, len)))
			return (0);
	}
	else
	{
		arg->n = (unsigned long)va_arg(*ap, long long);
		if (arg->type == TY_Z)
			arg->n = (size_t)arg->n;
		if (arg->type == TY_J)
			arg->n = (uintmax_t)arg->n;
		if (arg->type == TY_L)
			arg->n = (unsigned long)arg->n;
		if (!(handle_big_o(arg, len)))
			return (0);
	}
	return (1);
}
