/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:07:33 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 13:21:56 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		handle_big_c(t_arg *arg, size_t *len, t_wchart *w)
{
	char		tmp[w->len + 1];
	size_t		size;
	size_t		i;

	size = w->len;
	i = 0;
	while (w->len)
	{
		w->c = (w->all >> ((w->len - 1) * 8));
		tmp[i] = w->c;
		w->len = w->len - 1;
		i++;
	}
	tmp[i] = '\0';
	push_tmp(tmp, arg, len, size);
}

static void		handle_mini_c(t_arg *arg, va_list *ap, size_t *len)
{
	char		tmp[2];
	size_t		size;

	if (!(tmp[0] = (char)va_arg(*ap, int)))
	{
		push_tmp("", arg, len, 1);
		return ;
	}
	tmp[1] = '\0';
	size = ft_strlen(tmp);
	push_tmp(tmp, arg, len, size);
}

int				handle_character(t_arg *arg, va_list *ap, size_t *len)
{
	t_wchart	w;

	w.all = 0;
	w.len = 0;
	w.c = 0;
	if (arg->spec == 'c' && arg->type != TY_L)
		handle_mini_c(arg, ap, len);
	else
	{
		if (!(xseg_wchart(&w, (wchar_t)va_arg(*ap, wchar_t))))
		{
			ft_putstr_fd("Error handling 'C'", 1);
			return (0);
		}
		handle_big_c(arg, len, &w);
	}
	return (1);
}
