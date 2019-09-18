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

void				pad((void (*outc)(char)), t_args *args)
{
	while (args->width)
	{
		outc(args->flags & FZE ? '0' : ' ');
		args->width--;
	}
}

void				outBuf((void (*outc)(char), const char *buf, t_args *args))
{
	int				buffsize;

	buffsize = ft_strlen(buf);
	args->width -= buffsize;
	args->width = args->width < 0 ? 0 : args->width;
	if (!args->flags & FMI)
		pad(outc, args);
	while (buf++)
		outc(*buf);
	if (args->flags & FMI)
		pad(outc, args);
}

void				ft

void				format_character(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	wchar_t			c;

	c = va_arg(va, wchar_t);

	if (**fmt == 'C' || args->type & FL)
	{
	}
	if (**fmt == 'c')
		outBuf((char)c);
}
void				format_string(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	(void)outc;
	(void)fmt;
	(void)args;
	(void)va;
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
