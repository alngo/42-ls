/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:46:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 09:46:49 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			format_string(void (*outc)(char),\
		const char **fmt, t_args *args, va_list va)
{
	const char	*str;

	str = va_arg(va, const char *);
	if (**fmt == 'S' || args->type & TL)
		format_out(outc, str, args, **fmt);
	if (**fmt == 's')
		format_out(outc, str, args, **fmt);
}
