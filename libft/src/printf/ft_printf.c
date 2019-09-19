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

unsigned short		get_flags(const char **fmt, t_args *args)
{
	args->flags = 0;
	while (**fmt)
	{
		if (**fmt == ' ')
			args->flags |= FSP;
		else if (**fmt == '+')
			args->flags |= FPL;
		else if (**fmt == '-')
			args->flags |= FMI;
		else if (**fmt == '#')
			args->flags |= FNO;
		else if (**fmt == '0')
			args->flags |= FZE;
		else
			break;
		(*fmt)++;
	}
	return (args->flags);
}

unsigned int		get_width(const char **fmt, t_args *args, va_list va)
{
	int				w;

	args->width = 0;
	if (ft_isdigit(**fmt))
	{
		args->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (**fmt == '*') {
		w = va_arg(va, int);
		if (w < 0) {
			args->flags |= FMI;
			args->width = (unsigned int)-w;
		}
		else
			args->width = (unsigned int)w;
		(*fmt)++;
	}
	return (args->width);
}

unsigned int		get_precision(const char **fmt, t_args *args, va_list va)
{
	int				prec;

	args->precision = 0;
	if (**fmt == '.')
	{
		args->flags |= FPR;
		(*fmt)++;
	}
	if (ft_isdigit(**fmt))
	{
		args->precision = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (**fmt == '*') {
		prec = va_arg(va, int);
		args->precision = prec > 0 ? (unsigned int)prec : 0;
		(*fmt)++;
	}
	return (args->precision);
}

unsigned short		get_type(const char **fmt, t_args *args)
{
	args->type = 0;
	if (**fmt == 'l')
	{
		args->type |= FL;
		(*fmt)++;
		if (**fmt == 'l')
		{
			args->type |= FLL;
			(*fmt)++;
		}
	}
	else if (**fmt == 'h')
	{
		args->type |= FS;
		(*fmt)++;
		if (**fmt == 'h')
		{
			args->type |= FC;
			(*fmt)++;
		}
	}
	else if (**fmt == 'j')
	{
		args->type |= FTMAX;
		(*fmt)++;
	}
	else if (**fmt == 'z')
	{
		args->type |= FTSIZ;
		(*fmt)++;
	}
	return (args->type);
}

void				pad(void (*outc)(char), t_args *args)
{
	while (args->width)
	{
		outc(args->flags & FZE ? '0' : ' ');
		args->width--;
	}
}

void				outBuf(void (*outc)(char), const char *buf, t_args *args, uint8_t trim)
{
	size_t 			size;

	size = ft_strlen(buf);
	if (trim && args->precision)
		size = size < args->precision ? size : args->precision;
	args->width = args->width < size ? 0 : args->width - size;
	if (!(args->flags & FMI))
		pad(outc, args);
	while (size-- && *buf)
	{
		outc(*buf);
		buf++;
	}
	if (args->flags & FMI)
		pad(outc, args);
}

void				format_wide_character(wchar_t c, char *buf)
{
	wchar_t			code;

	code = 0;
	code |= (c & 63);
	code |= (((c >> 6) & 63) << 8);
	code |= (((c >> 12) & 63) << 16);
	code |= (((c >> 18) & 63) << 24);
	if (c <= 0177)
		code |= ENCODE_07BITS;
	else if (c < 03777)
		code |= (code | ENCODE_11BITS);
	else if (c < 0177777)
		code |= ENCODE_16BITS;
	else if (c < 04177777)
		code |= ENCODE_21BITS;
	else
		return;
	printf("code: %x\n", code);
	ft_memcpy(buf, &code, 4);
}

void				format_character(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	wchar_t			c;
	unsigned int	len;
	char			buf[5];


	c = (wchar_t)va_arg(va, wchar_t);
	len = 0;
	ft_bzero(buf, 5);
	if (**fmt == 'C' || args->type & FL)
		format_wide_character(c, buf);
	else if (**fmt == 'c')
		buf[0] = c ? (char)c : '\0';
	outBuf(outc, buf, args, 0);
}

void				format_string(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	const char 		*str;

	str = va_arg(va, const char *);
	if (**fmt == 'S' || args->type & FL)
		write(1, "/", 1);
	if (**fmt == 's')
		outBuf(outc, str, args, 1);
}

void				format_integer(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	(void)outc;
	(void)fmt;
	(void)args;
	(void)va;
}
void				format_pointer(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	(void)outc;
	(void)fmt;
	(void)args;
	(void)va;
}

void				formatter(void (*outc)(char), const char **fmt, t_args *args, va_list va)
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
	else if (**fmt == '%')
		outc(**fmt);
	else
		outc(**fmt);
	(*fmt)++;
}

int					xprintf(void (*outc)(char), const char *fmt, va_list va)
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
