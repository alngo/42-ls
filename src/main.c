/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/11/06 10:46:14 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(int ac, char **av)
{
	(void)ac;
	t_ls	ls;
	t_list	*directory_list;
	t_list	*other_list;

	ls.options = 0;
	ls.count = 0;
	ls.name = av[0];
	av++;

	retrieve_options(&av, &ls);
	retrieve_arguments(&av, &ls, &directory_list, &other_list);
	process_list(other_list, &ls);
	process_directory(directory_list, &ls);
	return (1);
}

int		main(int ac, char **av)
{
	int	ret;

	ret = ft_ls(ac, av);
	return (ret);
}
