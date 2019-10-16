/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:46:41 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 11:16:24 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			format_type(intmax_t *value, t_args *args, uint8_t di)
{
	intmax_t	val;

	val = *value;
	if (args->type & TZ)
		*value = (size_t)val;
	else if (args->type & TJ)
		*value = di ? (intmax_t)val : (uintmax_t)val;
	else if (args->type & TLL)
		*value = di ? (long long)val : (unsigned long long)val;
	else if (args->type & TL)
		*value = di ? (long)val : (unsigned long)val;
	else if (args->type & THH)
		*value = di ? (short)val : (unsigned short)val;
	else if (args->type & TH)
		*value = di ? (signed char)val : (unsigned char)val;
	else
		*value = (int)val;
}

void			format_integer(void (*outc)(char),\
		const char **fmt, t_args *args, va_list va)
{
	uint8_t		base;
	intmax_t	value;
	char		*tmp;

	value = (intmax_t)va_arg(va, intmax_t);
	if (**fmt == 'b')
		base = 2;
	else if (**fmt == 'o')
		base = 8;
	else if (**fmt == 'x' || **fmt == 'X')
		base = 16;
	else
		base = 10;
	format_type(&value, args, **fmt == 'd' || **fmt == 'i');
	tmp = ft_imaxtoa_base(value, base, "0123456789abcdef");
	format_out(outc, tmp, args, **fmt);
	if (tmp)
		free(tmp);
}
