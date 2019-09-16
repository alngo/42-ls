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

unsigned char		get_flags(const char **fmt, t_args *args)
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

unsigned char		get_type(const char **fmt, t_args *args)
{
	args->type = 0;
	if (**fmt == 'l')
	{
		args->type |= FL;
		if (*(*fmt)++ == 'l')
		{
			args->type |= FLL;
			(*fmt)++;
		}
	}
	else if (**fmt == 'h')
	{
		args->type |= FS;
		if (*(*fmt)++ == 'h')
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

//diouxfcspXb%

int					xprintf(void (*pf)(char), const char *fmt, va_list ap)
{
	t_args			args;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			get_flags(&fmt, &args);
			get_width(&fmt, &args, ap);
			get_precision(&fmt, &args, ap);
			get_type(&fmt, &args);

			printf("character after flags = %c\n", *fmt);
			printf("flags: %d\n", args.flags);
			printf("width: %d\n", args.width);
			printf("precision: %d\n", args.precision);
			printf("type %d\n", args.type);
		}
		else
		{
			pf(*fmt);
			fmt++;

		}
	}
	return (1);
}
