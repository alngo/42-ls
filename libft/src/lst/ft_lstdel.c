/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:48:33 by alngo             #+#    #+#             */
/*   Updated: 2019/06/04 10:32:57 by alngo            ###   ########.fr       */
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
