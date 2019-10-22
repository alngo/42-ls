/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 12:18:58 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(int ac, char **av)
{
	t_ls	ls;
	t_list	*directory_list;
	t_list	*other_list;

	ls.options = 0;
	ls.name = av[0];
	++av;
	ft_printf("--------PROCESSING-----------\n", ac);

	retrieve_options(&av, &ls);
	retrieve_arguments(&av, &ls, &directory_list, &other_list);
	process_list(other_list, &ls);
	ft_printf("-----------------------------\n", ac);

	displayListOrder(other_list);
	displayListOrder(directory_list);


	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);
	return (1);
}

int		main(int ac, char **av)
{
	int	ret;

	ret = ft_ls(ac, av);
	return (ret);
}
