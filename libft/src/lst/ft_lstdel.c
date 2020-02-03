/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:41:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 11:41:30 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*tmp;
	t_list			*tmpelem;

	if (alst == NULL)
		return ;
	tmpelem = *alst;
	while (tmpelem != NULL)
	{
		tmp = tmpelem->next;
		ft_lstdelone(&tmpelem, del);
		tmpelem = tmp;
	}
	*alst = NULL;
}
