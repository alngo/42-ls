/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 13:50:37 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		usage_out(t_ls *ls)
{
	ft_printf("usage: %s [-Ralrt] [file...]\n", ls->name);
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

void		set_options(char *arg, t_ls *ls)
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

void		get_options(char **av, t_ls *ls)
{
	while(*av)
	{
		ft_printf("%/g%s%/x\n", *av);
		if (*av[0] == '-')
			set_options(*av, ls);
		else
			break;
		av++;
	}
}

int		main(int ac, char **av)
{
	t_ls	ls;

	ls.options = 0;
	ls.name = av[0];

	av++;
	get_options(av, &ls);

	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
