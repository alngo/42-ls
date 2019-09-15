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
		width = ft_atoi(*fmt);
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

unsigned int		get_precision()


int					xprintf(void (*pf)(char), const char *fmt, va_list ap)
{
	unsigned char	flags;
	unsigned int	width;
	//unsigned int	precision;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			flags = get_flags(&fmt);
			width = get_width(&fmt, &flags, ap);
			printf("character after flags = %c\n", *fmt);
			printf("flags: %d\n", flags);
			printf("width: %d\n", width);
		}
		else
		{
			pf(*fmt);
			fmt++;

		}
	}
	return (1);
}
