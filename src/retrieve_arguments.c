/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:10:57 by alngo             #+#    #+#             */
/*   Updated: 2019/11/06 11:22:28 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*return_element(char *filepath, char *name)
{
	t_ls_arg	arg;
	t_list		*element;

	arg.filepath = filepath;
	arg.name = name;
	if (stat(filepath, &arg.stat) < 0)
		return (NULL);
	arg.owner = get_owner_name(arg.stat.st_uid);
	arg.group = get_group_name(arg.stat.st_gid);
	arg.bytes = get_bytes_formatted(arg.stat.st_size);
	arg.links = get_links_formatted(arg.stat.st_nlink);
	if (!(element = ft_lstnew(&arg, sizeof(t_ls_arg))))
		return (NULL);
	return (element);
}

void			insert_to_list(t_list **list,
		t_list *newElement, t_ls *ls)
{
	void		*func;
	t_ls_arg	*tmp;

	func = &lexicographicalOrder;
	tmp = (t_ls_arg *)newElement->content;
	if (!(ls->options & LS_OPT_SHOW_HIDDEN) && tmp->name[0] == '.')
		return ;
	if (ls->options & LS_OPT_REVERSE_ORDER)
		func = &lexicographicalOrderInverted;
	else if (ls->options & LS_OPT_SORT_BY_TIME)
		func = &sortByTime;
	ft_lstinsert(list, newElement, func);
}

void			insert_by_type(t_list **dir, t_list **other,
		t_list *newElement, t_ls *ls)
{
	t_ls_arg 	*tmp;

	tmp = (t_ls_arg *)newElement->content;
	if (S_ISDIR(tmp->stat.st_mode))
		insert_to_list(dir, newElement, ls);
	else
		insert_to_list(other, newElement, ls);
}

void			retrieve_arguments(char ***args, t_ls *ls,
		t_list **directory_list, t_list **other_list)
{
	t_list		*tmp;

	*directory_list = NULL;
	*other_list = NULL;
	while (**args)
	{
		if ((tmp = return_element(**args, **args)))
			insert_by_type(directory_list, other_list, tmp, ls);
		else
			ls_perror_out(ls, **args);
		(*args)++;
	}
}
