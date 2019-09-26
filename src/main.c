/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/26 20:08:54 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR			*return_directory(char *directory_name, t_ls *ls)
{
	DIR		*dirp;

	if ((dirp = opendir(directory_name)))
		return (dirp);
	else
		ls_perror_out(ls, directory_name);
	return (NULL);
}

void			add_directory(char *directory_name, t_ls *ls)
{
	t_directory	directory;
	t_list		*element;

	directory.dirp = return_directory(directory_name, ls);
	if (!directory.dirp)
		return ;
	element = ft_lstnew(&directory, sizeof(t_directory));
	ft_lstadd(&(ls->list), element);
}

void		loop_through_directories(char **av, t_ls *ls)
{
	if (!*av)
		add_directory(".", ls);
	else
	{
		while (*av)
		{
			add_directory(*av, ls);
			av++;
		}
	}
}


int		main(int ac, char **av)
{
	t_ls	ls;

	ls.options = 0;
	ls.name = av[0];

	av++;
	ft_printf("-----------------------------\n", ac);
	loop_through_options(av, &ls);
	loop_through_directories(av, &ls);



	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
