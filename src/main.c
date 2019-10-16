/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 17:13:26 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			retrieveLongestNameLength(t_list *list)
{
	t_ls_arg	*tmp;
	int		currentLength;
	int		longestNameLength;

	longestNameLength = 0;
	currentLength = 0;
	while (list)
	{
		tmp = (t_ls_arg *)list->content;
		currentLength = ft_strlen(tmp->name);
		if (longestNameLength < currentLength)
			longestNameLength = currentLength;
		list = list->next;
	}
	return (longestNameLength);
}


void			process_arguments(t_list *list, t_ls *ls)
{
	(void)list;
	(void)ls;
}

void			long_format_out(t_list *list)
{
	(void)list;

}

void			short_format_out(t_list *list)
{
	t_ls_arg	*tmp;
	int		padding;

	padding = retrieveLongestNameLength(list) + 1;
	while (list)
	{
		tmp = (t_ls_arg *)list->content;
		ft_printf("%-*s ", padding, tmp->name);
		list = list->next;
	}
	ft_printf("\n");
}

void			process_others(t_ls *ls)
{
	t_list		*list;

	list = ls->other_list;
	if (ls->options & LS_OPT_LONG_FORMAT)
		long_format_out(list);
	else
		short_format_out(list);
}

int		main(int ac, char **av)
{
	t_ls	ls;
	t_list	*list;
	char	**args;

	ls.options = 0;
	ls.name = av[0];
	ls.count = 0;
	list = NULL;
	args = ++av;
	ft_printf("--------PROCESSING-----------\n", ac);

	ls.options = retrieve_options(&args, &ls);
	list = retrieve_arguments(&args, &ls);
	process_others(&ls);
	process_arguments(list, &ls);

	ft_printf("-----------------------------\n", ac);
	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("Counter d'args: %/r%d%/x\n", ls.count);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
