/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:34:13 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 22:51:12 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		pre_parse(const char *fmt, va_list *args)
{
	t_arg		tmp;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (!(isparsable(*(fmt + 1))) && !(isspec(*(fmt + 1), &tmp)))
			{
				if (*(fmt + 1))
					fmt++;
				else
					return (1);
			}
			else
			{
				if (!(fmt = parse(fmt + 1, &tmp, args)))
					return (0);
			}
		}
		else
			fmt++;
	}
	return (1);
}

static char		ft_moultiplexer(t_arg *arg, va_list *ap, size_t *len)
{
	int			ret;

	ret = 0;
	if (arg->spec == '%')
		ret = handle_percent(arg, len);
	else if (arg->spec == 'p')
		ret = handle_pointer(arg, ap, len);
	else if (arg->spec == 'c' || arg->spec == 'C')
		ret = handle_character(arg, ap, len);
	else if (arg->spec == 's' || arg->spec == 'S')
		ret = handle_string(arg, ap, len);
	else if (arg->spec == 'd' || arg->spec == 'D' || arg->spec == 'i')
		ret = handle_decimal(arg, ap, len);
	else if (arg->spec == 'x' || arg->spec == 'X')
		ret = handle_hexadecimal(arg, ap, len);
	else if (arg->spec == 'o' || arg->spec == 'O')
		ret = handle_octal(arg, ap, len);
	else if (arg->spec == 'u' || arg->spec == 'U')
		ret = handle_unsigned(arg, ap, len);
	else if (arg->spec == 'b' || arg->spec == 'B')
		ret = handle_binary(arg, ap, len);
	else if (ft_isupper(arg->spec))
		ret = handle_upper(arg, ap, len);
	return (ret);
}

static char		*ft_handler(const char *fmt, va_list *ap, size_t *len)
{
	t_arg		tmp;

	tmp.n = 0;
	tmp.s = NULL;
	tmp.spec = 0;
	tmp.width = 0;
	tmp.prec = 0;
	tmp.flags = 0;
	tmp.type = 0;
	tmp.dot = 0;
	tmp.warn = 0;
	tmp.att = 0;
	tmp.length = 0;
	tmp.limit = 0;
	fmt = parse(fmt, &tmp, ap);
	if (!(ft_moultiplexer(&tmp, ap, len)))
		return (NULL);
	return ((char *)fmt);
}

static int		loooop(const char *fmt, size_t *len, va_list *ap, int fd)
{
	t_arg		tmp;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (!(isparsable(*(fmt + 1))) && !(isspec(*(fmt + 1), &tmp)))
				fmt++;
			else
			{
				if (!(fmt = (const char *)ft_handler(fmt + 1, ap, len)))
					return (-1);
			}
		}
		else
		{
			ft_putchar_fd(*fmt, fd);
			fmt++;
			*len = *len + 1;
		}
	}
	return (1);
}

int				ft_xprintf(const char *fmt, va_list *args, int fd)
{
	va_list		ap;
	size_t		len;

	va_copy(ap, *args);
	if (!(pre_parse(fmt, args)))
		return (-1);
	len = 0;
	loooop(fmt, &len, &ap, fd);
	return (len);
}
