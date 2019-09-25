/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:46:51 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 14:47:02 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		usage_out(t_ls *ls)
{
	ft_printf("usage: %s [-Ralrt] [file ...]\n", ls->name);
	exit(1);
}

void		illegal_option_out(t_ls *ls, char option)
{
	ft_printf("%s: illegal option -- %c\n", ls->name, option);
	usage_out(ls);
}

void		file_not_found_out(t_ls *ls, char *file_name)
{
	ft_printf("%s: %s: No such file or directory\n", ls->name, file_name);
}

void		permission_denied_out(t_ls *ls, char *file_name)
{
	ft_printf("%s: %s: Permission denied\n", ls->name, file_name);
}
