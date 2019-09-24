#include "ft_printf.h"
#include "libft.h"

void		get_flags(const char **fmt, t_args *args)
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
}

void		get_width(const char **fmt, t_args *args, va_list va)
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
}

void		get_precision(const char **fmt, t_args *args, va_list va)
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
}

void		get_type(const char **fmt, t_args *args)
{
	args->type = 0;
	if (**fmt == 'l' || **fmt == 'h')
	{
		args->type |= **fmt == 'l' ? TL : TH;
		(*fmt)++;
		if (**fmt == 'l' || **fmt == 'h')
		{
			args->type |= **fmt == 'l' ? TLL : THH;
			(*fmt)++;
		}
	}
	else if (**fmt == 'j' || **fmt == 'z')
	{
		args->type |= **fmt == 'j' ? TJ : TZ;
		(*fmt)++;
	}
}


