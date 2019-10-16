/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 12:18:18 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_ls	ls;
	t_list	*list;
	char	**args;

	ls.options = 0;
	ls.name = av[0];

	args = av;
	args++;
	ft_printf("-----------------------------\n");
	retrieve_options(&args, &ls);
	list = retrieve_arguments(&args, &ls);
	ft_printf("--------PROCESSING-----------\n", ac);
	ft_printf("-----------------------------\n", ac);

	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
