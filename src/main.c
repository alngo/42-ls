/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 10:10:23 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 			displayFileStat(const char *arg_name, struct stat *fileStat)
{
	printf("---------------------------\n");
	printf("Information for %s\n", arg_name);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n",fileStat->st_size);
	printf("Number of Links: \t%d\n",fileStat->st_nlink);
	printf("File inode: \t\t%llu\n",fileStat->st_ino);

	printf("File Permissions: \t");
	printf( (S_ISDIR(fileStat->st_mode)) ? "d" : "-");
	printf( (fileStat->st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat->st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat->st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat->st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat->st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat->st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat->st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat->st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat->st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");

	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat->st_mode)) ?
			"is" : "is not");
}

void	 displayListOrder(t_list *list)
{
	t_list		*tmp;
	t_ls_arg	*arg;

	tmp = list;
	if (list)
	{
		printf("[ORDER]: ");
		while (tmp)
		{
			arg = (t_ls_arg *)tmp->content;
			printf("%s -> ", arg->name);
			tmp = tmp->next;
		}
		printf("[END]\n");
	}
}

t_list			*return_element(char *arg_name)
{
	t_ls_arg	arg;
	t_list		*element;

	if (stat(arg_name, &arg.fileStat) < 0)
		return (NULL);
	displayFileStat(arg_name, &arg.fileStat);
	arg.name = arg_name;
	if (!(element = ft_lstnew(&arg, sizeof(t_ls_arg))))
		return (NULL);
	return (element);
}

int			lexicographicalOrder(void *content, void *contentToInsert)
{
	t_ls_arg	*element;
	t_ls_arg	*elementToInsert;

	element = (t_ls_arg *)content;
	elementToInsert = (t_ls_arg *)contentToInsert;

	return (ft_strcmp(element->name, elementToInsert->name));
}

int			lexicographicalOrderInverted(void *content, void *contentToInsert)
{
	t_ls_arg	*element;
	t_ls_arg	*elementToInsert;

	element = (t_ls_arg *)content;
	elementToInsert = (t_ls_arg *)contentToInsert;

	return (ft_strcmp(elementToInsert->name, element->name));
}

void			add_to_list(t_list *list, char *arg_name, t_ls *ls)
{
	t_list		*tmp;
	void		*func;

	func = &lexicographicalOrder;
	if (!(tmp = return_element(arg_name)))
		ls_perror_out(ls, arg_name);
	else
	{
		if (ls->options & LS_OPT_REVERSE_ORDER)
			func = &lexicographicalOrderInverted;
		ft_lstinsert(&list, tmp, func);
	}
}

t_list		*retrieve_args(char ***av, t_ls *ls)
{
	t_list	*list; (*av)++;

	if (**av)
		ft_printf("after options: %/r%s%/x\n", **av);

	list = NULL;
	if (!**av)
		add_to_list(list, ".", ls);
	else
		while (**av)
		{
			add_to_list(list, **av, ls);
			(*av)++;
		}

	displayListOrder(list);
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
	ft_printf("-----------------------------\n");
	retrieve_options(&args, &ls);
	ft_printf("-----------------------------\n");
	list = retrieve_args(&args, &ls);

	ft_printf("-----------------------------\n", ac);
	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
