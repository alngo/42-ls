/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:48:06 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:48:54 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				handle_upper(t_arg *arg, va_list *ap, size_t *len)
{
	char		tmp[2];
	size_t		size;

	(void)ap;
	if (!(tmp[0] = arg->spec))
	{
		push_tmp("", arg, len, 1);
		return (1);
	}
	tmp[1] = '\0';
	size = ft_strlen(tmp);
	push_tmp(tmp, arg, len, size);
	return (1);
}
