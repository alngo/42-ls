/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:06:47 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 13:14:14 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*flag_p(const char *s, t_arg *arg)
{
	char			*flags;

	arg->flags = 0;
	flags = " -+#0";
	while (ft_strchr(flags, *s))
	{
		if (*s == ' ')
			arg->flags |= SPF;
		if (*s == '+')
			arg->flags |= PL;
		if (*s == '-')
			arg->flags |= MI;
		if (*s == '#')
			arg->flags |= SH;
		if (*s == '0')
			arg->flags |= ZE;
		s++;
	}
	return ((char *)s);
}

static char			*width_p(const char *s, t_arg *arg, va_list *ap)
{
	arg->width = 0;
	if (*s == '*')
	{
		arg->att = 1;
		arg->wild = va_arg(*ap, int);
		if (arg->wild < 0)
		{
			arg->flags |= MI;
			arg->width = arg->wild * -1;
		}
		else
			arg->width = arg->wild;
		return ((char *)++s);
	}
	while (ft_isdigit(*s))
	{
		arg->width = arg->width * 10 + *s - '0';
		s++;
	}
	return ((char *)s);
}

static char			*prec_p(const char *s, t_arg *arg, va_list *ap)
{
	arg->dot = 1;
	arg->prec = 0;
	if (*s == '.')
		s++;
	if (*s == '*')
	{
		arg->wild = va_arg(*ap, int);
		arg->dot = arg->prec != 0 ? 0 : 1;
		if (arg->wild < 0)
		{
			arg->warn = 1;
			arg->prec = arg->wild * -1;
		}
		else
			arg->prec = arg->wild;
		return ((char *)++s);
	}
	while (ft_isdigit(*s))
	{
		arg->prec = arg->prec * 10 + *s - '0';
		s++;
		arg->dot = arg->prec != 0 ? 0 : 1;
	}
	return ((char *)s);
}

static char			*type_p(const char *s, t_arg *arg)
{
	arg->type = 0;
	if (*s == 'h')
		arg->type = (*(s + 1) == 'h') ? TY_HH : TY_H;
	if (*(s) == 'l')
		arg->type = (*(s + 1) == 'l') ? TY_LL : TY_L;
	if (*s == 'j')
		arg->type = TY_J;
	if (*s == 'z')
		arg->type = TY_Z;
	if (!(arg->type))
		return ((char *)s);
	if (arg->type == TY_HH || arg->type == TY_LL)
		return ((char *)s + 2);
	else
		return ((char *)s + 1);
}

char				*parse(const char *s, t_arg *arg, va_list *ap)
{
	while (isparsable(*s))
	{
		if (ft_strchr("#+-0 ", *s))
			s = flag_p(s, arg);
		if (ft_isdigit(*s) || *s == '*')
			s = width_p(s, arg, ap);
		if (*s == '.' || (*s == '.' && *(s + 1) == '*'))
			s = prec_p(s, arg, ap);
		if (ft_strchr("hljz", *s))
			s = type_p(s, arg);
	}
	if (!(isspec(*s, arg)))
		return (NULL);
	return ((char *)(s + 1));
}
