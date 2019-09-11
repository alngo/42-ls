/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:32:55 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 16:17:17 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_stoul_base(int *base, const char **sc,
					const char *s, char **end)
{
	if (*base < 0 || *base == 1 || MBASE < *base)
	{
		if (end)
			*end = (char *)s;
		return (0);
	}
	else if (*base)
	{
		if (*base == 16 && **sc == '0' && ft_tolower(*sc[1]) == 'x')
			*sc = *sc + 2;
	}
	else if (**sc != '0')
		*base = 10;
	else if (ft_tolower(*sc[1]) == 'x')
	{
		*base = 16;
		*sc = *sc + 2;
	}
	else
		*base = 8;
	return (*base);
}

static void			ft_xstoul(t_stoul *px, int base)
{
	while (ft_isspace(*(px->sc)))
		(px->sc)++;
	px->sign = *(px->sc) == '-' || *(px->sc) == '+' ? *(px->sc)++ : '+';
	px->s1 = px->sc;
	while (*(px->sc) == '0')
		(px->sc)++;
	px->x = 0;
	while ((px->sd = ft_memchr(px->digits, ft_tolower(*(px->sc)), base)))
	{
		px->x = (px->x * base + ((px->sd) - (px->digits)));
		(px->sc)++;
	}
}

unsigned long		ft_stoul(const char *s, char **end, int base)
{
	t_stoul			x;

	x.digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (!(ft_stoul_base(&base, &x.sc, s, end)))
		return (0);
	x.sc = s;
	ft_xstoul(&x, base);
	if ((x.s1) == (x.sc))
	{
		if (end)
			*end = (char *)s;
		return (0);
	}
	if (x.sign == '-')
		x.x = -(x.x);
	if (end)
		*end = (char *)(x.sc);
	return (x.x);
}
