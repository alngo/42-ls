#include "ft_printf.h"
#include "libft.h"

int					ft_printf(const char *fmt, ...)
{
	int				ans;
	va_list			ap;

	va_start(ap, fmt);
	ans = xprintf(&ft_putchar, fmt, ap);
	va_end(ap);
	return (ans);
}

unsigned char		get_flags(const char **fmt)
{
	unsigned char	flags;

	flags = 0;
	while (**fmt)
	{
		if (**fmt == ' ')
			flags |= FSP;
		else if (**fmt == '+')
			flags |= FPL;
		else if (**fmt == '-')
			flags |= FMI;
		else if (**fmt == '#')
			flags |= FNO;
		else if (**fmt == '0')
			flags |= FZE;
		else
			break;
		(*fmt)++;
	}
	return (flags);
}

unsigned int		get_width(const char **fmt, unsigned char *flags, va_list va)
{
	unsigned int	width;
	int				w;

	width = 0;
	if (ft_isdigit(**fmt))
	{
		width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (**fmt == '*') {
		w = va_arg(va, int);
		if (w < 0) {
			*flags |= FMI;
			width = (unsigned int)-w;
		}
		else
			width = (unsigned int)w;
		(*fmt)++;
	}
	return (width);
}

unsigned int		get_precision(const char **fmt, unsigned char *flags, va_list va)
{
	unsigned int	precision;
	int				prec;

	precision = 0;
	if (**fmt == '.')
	{
		*flags |= FPR;
		(*fmt)++;
	}
	if (ft_isdigit(**fmt))
	{
		prec = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (**fmt == '*') {
		prec = va_arg(va, int);
		precision = prec > 0 ? (unsigned int)prec : 0;
		(*fmt)++;
	}
	return (precision);
}

unsigned char		get_type(const char **fmt)
{
	unsigned char	type;

	if (**fmt == 'l')
	{
		type |= FL;
		if (*(*fmt)++ == 'l')
		{
			type |= FLL;
			(*fmt)++;
		}
	}
	else if (**fmt == 'h')
	{
		type |= FS;
		if (*(*fmt)++ == 'h')
		{
			type |= FC;
			(*fmt)++;
		}
	}
	else if (**fmt == 'j')
	{
		type |= FTMAX;
		(*fmt)++;
	}
	else if (**fmt == 'z')
	{
		type |= FTSIZ;
		(*fmt)++;
	}
	return (type)
}


int					xprintf(void (*pf)(char), const char *fmt, va_list ap)
{
	unsigned char	flags;
	unsigned char	type;
	unsigned int	width;
	unsigned int	precision;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			flags = get_flags(&fmt);
			width = get_width(&fmt, &flags, ap);
			precision = get_precision(&fmt, &flags, ap);
			printf("character after flags = %c\n", *fmt);
			printf("flags: %d\n", flags);
			printf("width: %d\n", width);
			printf("precision: %d\n", precision);
		}
		else
		{
			pf(*fmt);
			fmt++;

		}
	}
	return (1);
}
