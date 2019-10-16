/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:10:57 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 14:25:13 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*return_element(char *arg_name)
{
	t_ls_arg	arg;
	t_list		*element;

	arg.name = arg_name;
	if (stat(arg_name, &arg.stat) < 0)
		return (NULL);
	if (!(element = ft_lstnew(&arg, sizeof(t_ls_arg))))
		return (NULL);
	return (element);
}

void			add_to_list(t_list **list, t_list *newElement, t_ls *ls)
{
	void		*func;

	func = &lexicographicalOrder;
	if (ls->options & LS_OPT_REVERSE_ORDER)
		func = &lexicographicalOrderInverted;
	else if (ls->options & LS_OPT_SORT_BY_TIME)
		func = &sortByTime;
	ft_lstinsert(list, newElement, func);
}


t_list		*retrieve_arguments(char ***args, t_ls *ls)
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	while (**args)
	{
		if ((tmp = return_element(**args)))
			add_to_list(&list, tmp, ls);
		else
			ls_perror_out(ls, **args);
		(*args)++;
		ls->count++;
	}
	return (list);
}
