/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:08:43 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 12:20:03 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_options(char *arg, uint8_t *options, t_ls *ls)
{
	arg++;
	while(*arg)
	{
		if (*arg == 'R')
			*options |= LS_OPT_RECURSIVE;
		else if (*arg == 'a')
			*options |= LS_OPT_INCLUDE_DOT;
		else if (*arg == 'l')
			*options |= LS_OPT_LONG_FORMAT;
		else if (*arg == 'r')
			*options |= LS_OPT_REVERSE_ORDER;
		else if (*arg == 't')
			*options |= LS_OPT_SORT_BY_TIME;
		else
			illegal_option_out(ls, *arg);
		arg++;
	}
}

void 		retrieve_options(char ***args, t_ls *ls)
{
	while(**args)
	{
		if (**args[0] == '-')
			parse_options(**args, &ls->options, ls);
		else
			break;
		(*args)++;
	}
}
