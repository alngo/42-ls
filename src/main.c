/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 12:26:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		illegal_option_out(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	usage_out();
}

void		file_not_found_out(char *name)
{
	ft_printf("ls: %s: No such file or directory\n", name);
}

void		usage_out()
{
	ft_printf("usage: ls [-Ralrt] [file...]\n");
}

void		ls_flags(char **av, uint8_t *flags)
{
	(void)flags;
	while(*av)
	{
		ft_printf("%/g%s%/x\n", *av);
		av++;
	}
}

int		main(int ac, char **av)
{
	uint8_t flags;
	(void)av;

	flags = 0;
	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ls_flags(av, &flags);

	return (1);
}
