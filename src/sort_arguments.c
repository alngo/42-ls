/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:09:22 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 11:05:58 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			lexicographicalOrder(void *contentToInsert, void *content)
{
	t_ls_arg	*element;
	t_ls_arg	*elementToInsert;

	element = (t_ls_arg *)content;
	elementToInsert = (t_ls_arg *)contentToInsert;

	return (ft_strcmp(elementToInsert->filepath, element->filepath));
}

int			lexicographicalOrderInverted(void *contentToInsert, void *content)
{
	t_ls_arg	*element;
	t_ls_arg	*elementToInsert;

	element = (t_ls_arg *)content;
	elementToInsert = (t_ls_arg *)contentToInsert;

	return (ft_strcmp(element->filepath, elementToInsert->filepath));
}

int			compareTimestamp(long a, long b)
{
	if (a < b)
		return (1);
	else if (a > b)
		return (-1);
	else
		return (0);
}

int			sortByTime(void *contentToInsert, void *content)
{
	t_ls_arg	*element;
	t_ls_arg	*elementToInsert;


	element = (t_ls_arg *)content;
	elementToInsert = (t_ls_arg *)contentToInsert;

	return (compareTimestamp(elementToInsert->stat.st_mtime,
				element->stat.st_mtime));
}
