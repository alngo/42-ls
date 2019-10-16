/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:10:57 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 12:19:02 by alngo            ###   ########.fr       */
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

void			add_to_list(t_list **list, char *arg_name, t_ls *ls)
{
	t_list		*tmp;
	void		*func;

	func = &lexicographicalOrder;
	if ((tmp = return_element(arg_name)))
	{
		if (ls->options & LS_OPT_REVERSE_ORDER)
			func = &lexicographicalOrderInverted;
		else if (ls->options & LS_OPT_SORT_BY_TIME)
			func = &sortByTime;
		ft_lstinsert(list, tmp, func);
	}
	else
		ls_perror_out(ls, arg_name);
}

t_list		*retrieve_arguments(char ***args, t_ls *ls)
{
	t_list	*list;

	list = NULL;
	if (**args)
	{
		while (**args)
		{
			add_to_list(&list, **args, ls);
			(*args)++;
		}
	}
	else
		add_to_list(&list, ".", ls);
	return (list);
}

