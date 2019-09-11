/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:07:55 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 21:45:22 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			handle_percent(t_arg *arg, size_t *len)
{
	char	*tmp;
	size_t	size;

	tmp = "%";
	size = ft_strlen(tmp);
	push_tmp(tmp, arg, len, size);
	return (1);
}
