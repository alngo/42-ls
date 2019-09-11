/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:51:09 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:38:35 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*format_hexadecimal(t_arg *arg, char *buf, size_t size)
{
	char		*tmp;
	size_t		add;
	size_t		i;

	i = 0;
	add = (arg->flags & SH && arg->n) ? 2 : 0;
	add += (arg->prec > size) ? (arg->prec - size) : 0;
	add += (arg->flags & SH && arg->flags & ZE && arg->width > size) &&
		!(arg->flags & MI) ? arg->width - size - 2 : 0;
	if (!(tmp = ft_strnew(size + add)))
		return (NULL);
	while (add)
	{
		tmp[i++] = '0';
		add--;
	}
	while (*buf)
	{
		tmp[i++] = *buf;
		buf++;
	}
	tmp[i] = '\0';
	if (arg->flags & SH && arg->n)
		tmp[1] = (arg->spec == 'x') ? 'x' : 'X';
	return (tmp);
}

static int		handle_minibig_x(t_arg *arg, size_t *len)
{
	char		*buf;
	char		*tmp;
	size_t		size;

	if (!(buf = ft_litob(arg->n, arg, 16, arg->spec == 'x' ?
			"0123456789abcdef" : "0123456789ABCDEF")))
		return (0);
	if (arg->dot && !(arg->n))
		buf[0] = '\0';
	if (!(tmp = format_hexadecimal(arg, buf, ft_strlen(buf))))
		return (0);
	size = ft_strlen(tmp);
	push_tmp(tmp, arg, len, size);
	free(buf);
	free(tmp);
	return (1);
}

int				handle_hexadecimal(t_arg *arg, va_list *ap, size_t *len)
{
	if (arg->type == TY_L)
		arg->n = (long)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_LL)
		arg->n = (long long)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_J)
		arg->n = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_Z)
		arg->n = (size_t)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_HH)
		arg->n = (unsigned char)va_arg(*ap, unsigned long long);
	else if (arg->type == TY_H)
		arg->n = (unsigned short)va_arg(*ap, unsigned long long);
	else
		arg->n = (unsigned int)va_arg(*ap, unsigned long long);
	if (!(handle_minibig_x(arg, len)))
		return (0);
	return (1);
}
