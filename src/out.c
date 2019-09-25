/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:46:51 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 16:56:16 by alngo            ###   ########.fr       */
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

void 		ls_perror_out(t_ls *ls, char *name)
{
	ft_printf("%s: %s: ", ls->name, name);
	perror("");
}


