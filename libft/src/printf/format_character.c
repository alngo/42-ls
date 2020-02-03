/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:46:03 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 09:46:04 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			format_wide_character(wchar_t c, char *buf)
{
	wchar_t		code;

	code = 0;
	ft_bzero(buf, 5);
	code |= (c & 63);
	code |= (((c >> 6) & 63) << 8);
	code |= (((c >> 12) & 63) << 16);
	code |= (((c >> 18) & 63) << 24);
	if (c <= 0177)
		code = (code | ENCODE_07BITS) << 24;
	else if (c < 03777)
		code = (code | ENCODE_11BITS) << 16;
	else if (c < 0177777)
		code = (code | ENCODE_16BITS) << 8;
	else if (c < 04177777)
		code |= ENCODE_21BITS;
	else
		return ;
	buf[0] = ((char *)&code)[3];
	buf[1] = ((char *)&code)[2];
	buf[2] = ((char *)&code)[1];
	buf[3] = ((char *)&code)[0];
}

void			format_character(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va)
{
	wchar_t		c;
	char		buf[5];

	c = (wchar_t)va_arg(va, wchar_t);
	ft_bzero(buf, 5);
	if (**fmt == 'C' || args->type & TL)
		format_wide_character(c, buf);
	else if (**fmt == 'c')
		buf[0] = c ? (unsigned char)c : '\0';
	if (!buf[0])
		error_out(outc, **fmt);
	format_out(outc, buf, args, **fmt);
}
