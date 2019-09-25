/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:56:31 by alngo             #+#    #+#             */
/*   Updated: 2019/09/18 14:59:33 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int					ft_printf(const char *fmt, ...)
{
	int				ans;
	va_list			va;

	va_start(va, fmt);
	ans = xprintf(&ft_putchar, fmt, va);
	va_end(va);
	return (ans);
}

int					xprintf(void (*outc)(char), const char *fmt,\
		va_list va)
{
	t_args			args;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			get_flags(&fmt, &args);
			get_width(&fmt, &args, va);
			get_precision(&fmt, &args, va);
			get_type(&fmt, &args);
			formatter(outc, &fmt, &args, va);
		}
		else
		{
			outc(*fmt);
			fmt++;
		}
	}
	return (1);
}
