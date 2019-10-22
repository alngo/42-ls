/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_field_out2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:59:48 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 13:04:42 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			number_of_byte_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->bytes, arg->bytes);
}

void 			date_last_modified_out(struct stat filestat)
{
	char		*tmp;

	tmp = ctime(&filestat.st_mtime);
	tmp += 4;
	ft_printf("%.12s", tmp);
}

void			filepath_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%-*s", pad->filepath, arg->filepath);
}
