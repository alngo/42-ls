/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:06:51 by alngo             #+#    #+#             */
/*   Updated: 2017/06/28 19:06:25 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *fmt, ...)
{
	va_list		args;
	size_t		ret;

	va_start(args, fmt);
	ret = ft_xprintf(fmt, &args, 1);
	va_end(args);
	return (ret);
}
