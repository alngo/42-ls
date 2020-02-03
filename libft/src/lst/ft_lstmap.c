/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:42:04 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 11:42:05 by alngo            ###   ########.fr       */
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
