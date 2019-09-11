/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:08:12 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:58:38 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	set_size(t_arg *arg, char c)
{
	size_t		ret;

	ret = arg->length;
	if ((arg->prec || arg->dot) && c && (arg->prec < ret))
	{
		if (arg->dot)
			return (0);
		else
			return (arg->limit);
	}
	return (ret);
}

static void		xhandle_big_s(t_arg *arg, t_wchart *w, size_t *len, size_t n)
{
	char		tmp[arg->length];
	size_t		size;
	size_t		i;

	i = 0;
	while (n)
	{
		arg->limit += w->len;
		arg->tmp = w->len;
		while (arg->tmp)
		{
			w->c = (w->all >> ((arg->tmp - 1) * 8));
			tmp[i] = w->c;
			arg->tmp = arg->tmp - 1;
			i++;
		}
		n--;
		w++;
		if (arg->limit + w->len > arg->prec && arg->prec && n)
			break ;
	}
	size = set_size(arg, tmp[0]);
	push_tmp(tmp, arg, len, size);
}

static int		handle_big_s(t_arg *arg, wchar_t *str,
		size_t *len, size_t n)
{
	t_wchart	w[n];
	size_t		i;

	i = 0;
	arg->length = 0;
	while (str[i])
	{
		if (!(xseg_wchart(&w[i], str[i])))
			return (0);
		arg->length += w[i].len;
		i++;
	}
	xhandle_big_s(arg, w, len, n);
	return (1);
}

static void		handle_mini_s(t_arg *arg, va_list *ap, size_t *len)
{
	char		*tmp;
	size_t		size;

	if (!(tmp = (char *)va_arg(*ap, char *)))
	{
		if (arg->width && !arg->att)
			push_tmp("", arg, len, 0);
		else
			push_tmp("(null)", arg, len, 6);
		return ;
	}
	size = ft_strlen(tmp);
	size = ((arg->prec || arg->dot) && tmp[0] &&
			(arg->prec < size)) ? arg->prec : size;
	push_tmp(tmp, arg, len, size);
}

int				handle_string(t_arg *arg, va_list *ap, size_t *len)
{
	wchar_t		*tmp;
	size_t		n;

	tmp = NULL;
	if (arg->spec == 's' && arg->type != TY_L)
		handle_mini_s(arg, ap, len);
	else
	{
		n = 0;
		if (!(tmp = (wchar_t *)va_arg(*ap, wchar_t *)))
		{
			push_tmp("(null)", arg, len, 6);
			return (1);
		}
		while (tmp[n])
			n++;
		if (!(handle_big_s(arg, tmp, len, n)))
			ft_putstr_fd("Error handling 'S'", 1);
	}
	return (1);
}
