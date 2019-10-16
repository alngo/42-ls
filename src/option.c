/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:47:15 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 11:29:29 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_options(char *arg, t_ls *ls)
{
	arg++;
	while(*arg)
	{
		if (*arg == 'R')
			ls->options |= LS_OPT_RECURSIVE;
		else if (*arg == 'a')
			ls->options |= LS_OPT_INCLUDE_DOT;
		else if (*arg == 'l')
			ls->options |= LS_OPT_LONG_FORMAT;
		else if (*arg == 'r')
			ls->options |= LS_OPT_REVERSE_ORDER;
		else if (*arg == 't')
			ls->options |= LS_OPT_SORT_BY_TIME;
		else
			illegal_option_out(ls, *arg);
		arg++;
	}
}

void		retrieve_options(char ***args, t_ls *ls)
{
	while(**args)
	{
		if (**args[0] == '-')
			parse_options(**args, ls);
		else
			break;
		(*args)++;
	}
}
