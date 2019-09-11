/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:35:50 by alngo             #+#    #+#             */
/*   Updated: 2017/01/06 15:36:12 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void			miniprintf(const char *fmt, ...)
{
	va_list	ap;
	char	*tmp;

	va_start(ap, fmt);
	tmp = (char *)fmt;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			if (*(++tmp) == 's')
				ft_putstr(va_arg(ap, char *));
			else if (*tmp == 'd')
				ft_putnbr(va_arg(ap, int));
			else if (*tmp == 'c')
				ft_putchar(va_arg(ap, int));
			else
				ft_putchar(*tmp);
			tmp++;
		}
		ft_putchar(*tmp);
		tmp++;
	}
	va_end(ap);
}
