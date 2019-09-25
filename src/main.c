/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 16:14:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_directory(char *directory_name, t_ls *ls)
{
	(void)directory_name;
	(void)ls;
}

void		loop_through_directories(char **av, t_ls *ls)
{
	if (!av)
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
	loop_through_options(av, &ls);
	loop_through_directories(av, &ls);



	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
