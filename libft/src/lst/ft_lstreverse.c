/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:30:49 by alngo             #+#    #+#             */
/*   Updated: 2019/06/04 10:33:13 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstreverse(t_list *lst)
{
	t_list		*prev;
	t_list		*next;

	prev = NULL;
	while (lst)
	{
		next = lst->next;
		lst->next = prev;
		prev = lst;
		lst = next;
	}
	return (prev);
}
