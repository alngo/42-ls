/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:42:33 by alngo             #+#    #+#             */
/*   Updated: 2019/06/04 10:33:09 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list				*new;
	t_list				*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = (*f)(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = (*f)(lst);
		new = new->next;
	}
	return (tmp);
}
