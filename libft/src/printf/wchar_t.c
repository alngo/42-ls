/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:36:19 by alngo             #+#    #+#             */
/*   Updated: 2017/07/03 14:49:57 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			xfill_wchart(t_wchart *w, wchar_t c, int shape, int i)
{
	w->all = shape;
	w->len = i;
	if (i == 1)
	{
		w->all = w->all | c;
		return (1);
	}
	while (i)
	{
		w->all = w->all | ((c >> (6 * (i - 1))) & 63) << (8 * (i - 1));
		i--;
	}
	return (1);
}

int					xseg_wchart(t_wchart *w, wchar_t c)
{
	w->len = 0;
	while (c >> w->len)
		w->len++;
	if (w->len > 21)
		return (0);
	if (w->len <= 7)
		return (xfill_wchart(w, c, WCHAR_07BITS, 1));
	else if (w->len > 7 && w->len <= 11)
		return (xfill_wchart(w, c, WCHAR_11BITS, 2));
	else if (w->len > 11 && w->len <= 16)
		return (xfill_wchart(w, c, WCHAR_16BITS, 3));
	else if (w->len > 16 && w->len <= 21)
		return (xfill_wchart(w, c, WCHAR_21BITS, 4));
	return (1);
}
