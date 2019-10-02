/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/02 16:27:23 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR			*return_directory(char *directory_name)
{
	DIR	*dirp;

	if (!(dirp = opendir(directory_name)))
		return (NULL);
	return (dirp);
}

t_list			*return_element(char *directory_name)
{
	t_ls_element	el;
	t_list		*element;

	if (!(directory.dirp = return_directory(directory_name)))
		return (NULL);
	if (!(element = ft_lstnew(&directory, sizeof(t_directory))))
		return (NULL);
	return (element);
}


void			add_to_list(t_list *list, char *directory_name, t_ls *ls)
{
	t_ls_elememt	*tmp;

	ft_printf("%/g%s%/x\n", directory_name);
	if (!(tmp = return_element(directory_name)))
		ls_perror_out(ls, directory_name);
	else
		ft_lstadd(&list, tmp);
}

t_list		*retrieve_args(char ***av, t_ls *ls)
{
	t_list	*list;

	list = NULL;
	if (!**av)
		add_to_list(list, ".", ls);
	else
		while (**av)
		{
			add_to_list(list, **av, ls);
			(*av)++;
		}
	return (list);
}

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

	ft_printf("after options: %/r%s%/x\n", *args);
	ft_printf("-----------------------------\n");
	list = retrieve_args(&args, &ls);

	ft_printf("-----------------------------\n", ac);
	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
