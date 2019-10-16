/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 11:34:30 by alngo            ###   ########.fr       */
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
		ft_printf("%/g[ORDER]%/x: => ");
		while (tmp)
		{
			arg = (t_ls_arg *)tmp->content;
			ft_printf("%s -> ", arg->name);
			tmp = tmp->next;
		}
		ft_printf("%/g[END]%/x\n");
	}
}

t_list			*return_element(char *arg_name)
{
	t_ls_arg	arg;
	t_list		*element;

	if (stat(arg_name, &arg.stat) < 0)
		return (NULL);
	arg.name = arg_name;
	if (!(element = ft_lstnew(&arg, sizeof(t_ls_arg))))
		return (NULL);
	return (element);
}

void			add_to_list(t_list **list, char *arg_name, t_ls *ls)
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
		ft_lstinsert(list, tmp, func);
	}
}

t_list		*retrieve_args(char ***args, t_ls *ls)
{
	t_list	*list;

	list = NULL;
	if (!**args)
		add_to_list(&list, ".", ls);
	else
		while (**args)
		{
			add_to_list(&list, **args, ls);
			(*args)++;
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
	args++;
	ft_printf("-----------------------------\n");
	retrieve_options(&args, &ls);
	ft_printf("-----------------------------\n");
	list = retrieve_args(&args, &ls);

	ft_printf("-----------------------------\n", ac);
	ft_printf("Nombre d'args: %/r%d%/x\n", ac);
	ft_printf("options: %/r%#.8b%/x\n", ls.options);

	return (1);
}
