/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:07:49 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 13:14:14 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*format_decimal(t_arg *arg, char *buf, size_t size)
{
	char		*tmp;
	size_t		add;
	size_t		i;

	i = 0;
	add = arg->flags & PL || arg->nb < 0 ? 1 : 0;
	add += (arg->flags & SPF && !(arg->flags & PL) && !(arg->nb < 0)) ? 1 : 0;
	add += (arg->prec > size) ? (arg->prec - size) : 0;
	if (arg->flags & ZE && (arg->width > size) && !(arg->prec) &&
			!(arg->flags & MI))
		add += (arg->width - size) - ((arg->flags & PL ||
					arg->nb < 0 || arg->flags & SPF) ? 1 : 0);
	if (!(tmp = ft_strnew(size + add)))
		return (NULL);
	if (arg->flags & SPF && !(arg->flags & PL) && !(arg->nb < 0))
		tmp[i++] = ' ';
	if (arg->flags & PL || arg->nb < 0 || (arg->flags & ZE && arg->flags & PL))
		tmp[i++] = arg->nb < 0 ? '-' : '+';
	while (i < add)
		tmp[i++] = '0';
	while (*buf)
		tmp[i++] = *(buf++);
	tmp[i] = '\0';
	return (tmp);
}

static int		handle_big_d(t_arg *arg, size_t *len)
{
	char		*buf;
	char		*tmp;
	size_t		size;

	if (!(buf = ft_litob(ABS(arg->nb), arg, 10, "0123456789abcdef")))
		return (0);
	if (arg->dot && !(arg->nb))
		buf[0] = '\0';
	if (!(tmp = format_decimal(arg, buf, ft_strlen(buf))))
		return (0);
	size = ft_strlen(tmp);
	if (arg->prec)
		arg->flags &= ~ZE;
	push_tmp(tmp, arg, len, size);
	free(tmp);
	free(buf);
	return (1);
}

static int		handle_mini_di(t_arg *arg, size_t *len)
{
	char		*buf;
	char		*tmp;
	size_t		size;

	if (arg->type == TY_HH)
		arg->nb = (signed char)arg->nb;
	if (arg->type == TY_H)
		arg->nb = (short)arg->nb;
	if (!(buf = ft_litob(ABS(arg->nb), arg, 10, "0123456789abcdef")))
		return (0);
	if (arg->dot && !(arg->nb))
		buf[0] = '\0';
	if (!(tmp = format_decimal(arg, buf, ft_strlen(buf))))
		return (0);
	size = ft_strlen(tmp);
	if (arg->prec)
		arg->flags &= ~ZE;
	push_tmp(tmp, arg, len, size);
	free(tmp);
	free(buf);
	return (1);
}

int				handle_decimal(t_arg *arg, va_list *ap, size_t *len)
{
	if (arg->warn)
		arg->prec = 0;
	if ((arg->spec == 'd' || arg->spec == 'i') && arg->type != TY_L &&
			arg->type != TY_LL && arg->type != TY_J && arg->type != TY_Z)
	{
		arg->nb = (int)va_arg(*ap, int);
		if (!(handle_mini_di(arg, len)))
			return (0);
	}
	else
	{
		arg->nb = (long long)va_arg(*ap, long long);
		if (arg->type == TY_Z)
			arg->nb = (ssize_t)arg->nb;
		if (arg->type == TY_J)
			arg->nb = (intmax_t)arg->nb;
		if (arg->type == TY_L)
			arg->nb = (long)arg->nb;
		if (!(handle_big_d(arg, len)))
			return (0);
	}
	return (1);
}
