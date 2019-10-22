/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_formatted_field_out.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:30 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 12:49:40 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			number_of_byte_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->bytes, arg->bytes);
}

void 			date_last_modified_out(struct stat fileStat)
{
	char		*tmp;

	tmp = ctime(&fileStat.st_mtime);
	ft_printf("%s", tmp);
}
