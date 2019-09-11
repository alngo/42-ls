/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:38:47 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:38:35 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*format_binary(t_arg *arg, char *buf, size_t size)
{
	char		*tmp;
	size_t		add;
	size_t		i;

	i = 0;
	add = (arg->prec > size) ? (arg->prec - size) : 0;
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

static int		handle_big_b(t_arg *arg, size_t *len)
{
	char		*buf;
	char		*tmp;
	size_t		size;

	if (!(buf = ft_litob(arg->n, arg, 2, "0123456789abcdef")))
		return (0);
	if (arg->dot && !(arg->n))
		buf[0] = '\0';
	if (!(tmp = format_binary(arg, buf, ft_strlen(buf))))
		return (0);
	size = ft_strlen(tmp);
	if (arg->prec)
		arg->flags &= ~ZE;
	push_tmp(tmp, arg, len, size);
	free(tmp);
	free(buf);
	return (1);
}

int				handle_binary(t_arg *arg, va_list *ap, size_t *len)
{
	if (arg->type == TY_HH && arg->spec != 'U')
		arg->n = (unsigned char)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_H && arg->spec != 'U')
		arg->n = (unsigned short)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_L || arg->spec == 'U')
		arg->n = (unsigned long)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_LL)
		arg->n = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_J)
		arg->n = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_Z)
		arg->n = (size_t)va_arg(*ap, unsigned long long);
	else
		arg->n = (unsigned int)va_arg(*ap, unsigned long long);
	if (!(handle_big_b(arg, len)))
		return (0);
	return (1);
}
