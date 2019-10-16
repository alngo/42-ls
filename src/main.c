/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 14:36:51 by alngo            ###   ########.fr       */
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

void			ft_lstremove(t_list **alst)

const sanitize_arguments(t_list *list, t_ls *ls)
{
	t_list		*directories;
	t_list		*files;
	t_ls_arg 	*tmp;

	while (*list)
	{
		tmp = (t_ls_arg *)list->content;
		if (S_ISDIR(tmp.stat.st_mode))
			ft_lst



	}
}

void			process_arguments(t_list *list, t_ls ls)
{
	(void)list;
	(void)ls;
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
	ft_printf("-----------------------------\n");

	ls.options = retrieve_options(&args, &ls);
	list = retrieve_arguments(&args, &ls);
	list = sanitize_arguments(list, &ls);

	ft_printf("--------PROCESSING-----------\n", ac);

	process_arguments(list, ls);

	ft_printf("-----------------------------\n", ac);
	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("Counter d'args: %/r%d%/x\n", ls.count);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
