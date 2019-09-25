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

void				format_color(void (*outc)(char), const char **fmt)
{
	(*fmt)++;
	if (**fmt == 'R' )
		buffer_out(outc, RED, 10);
	else if (**fmt == 'G')
		buffer_out(outc, GREEN, 10);
	else if (**fmt == 'B')
		buffer_out(outc, BLUE, 10);
	else if (**fmt == 'Y')
		buffer_out(outc, YELLOW, 10);
	else if (**fmt == 'M')
		buffer_out(outc, MAGENTA, 10);
	else if (**fmt == 'C')
		buffer_out(outc, CYAN, 10);
	else if (**fmt == 'X')
		buffer_out(outc, NOCOLOR, 7);
}

void				formatter(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va)
{
	if (**fmt == 'c' || **fmt == 'C')
		format_character(outc, fmt, args, va);
	else if (**fmt == 's' || **fmt == 'S')
		format_string(outc, fmt, args, va);
	else if (**fmt == 'b' || **fmt == 'o' || **fmt == 'd' || **fmt == 'D' ||
			**fmt == 'i' || **fmt == 'u' || **fmt == 'x' || **fmt == 'X')
		format_integer(outc, fmt, args, va);
	else if (**fmt == 'p')
		format_pointer(outc, fmt, args, va);
	else if (**fmt == '/')
		format_color(outc, fmt);
	else if (**fmt == '%')
		outc(**fmt);
	else
		outc(**fmt);
	(*fmt)++;
}
