/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:45:10 by alngo             #+#    #+#             */
/*   Updated: 2019/11/06 11:51:56 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_bytes(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->bytes, arg->bytes);
}

void 			print_mtime(struct stat filestat)
{
	char		*tmp;

	tmp = ctime(&filestat.st_mtime);
	tmp += 4;
	ft_printf("%.12s", tmp);
}

void			print_name(t_ls_arg *arg, t_ls_padding *pad)
{
	char		type;

	type = arg->filetype;
	if (type == 'd')
		ft_printf("%/b%-*s%/x", pad->name, arg->name);
	else if (type == 'l')
		ft_printf("%/g%-*s%/x", pad->name, arg->name);
	else
		ft_printf("%-*s", pad->name, arg->name);
}
