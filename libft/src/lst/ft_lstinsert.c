/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:19:37 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 11:01:04 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstinsert(t_list **alst, t_list *newelem,
		int (*cmp)(void *, void *))
{
	t_list		*tmp;

	if (!(*alst))
		*alst = newelem;
	else if ((*cmp)(newelem->content, (*alst)->content) < 0)
	{
		newelem->next = *alst;
		*alst = newelem;
	}
	else
	{
		tmp = *alst;
		while ((tmp->next) && (*cmp)(newelem->content, tmp->next->content) > 0)
			tmp = tmp->next;
		newelem->next = tmp->next;
		tmp->next = newelem;
	}
}
