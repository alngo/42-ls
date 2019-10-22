/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:13:29 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 13:17:04 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			set_padding(t_list *list, t_ls_padding *pad)
{
	t_ls_arg	*tmp;
	int		filepath_len;
	int		owner_name_len;
	int		group_name_len;
	int		links_len;
	int		bytes_len;

	while (list)
	{
		tmp = (t_ls_arg *)list->content;

		filepath_len = ft_strlen(tmp->filepath);
		owner_name_len = ft_strlen(tmp->owner);
		group_name_len = ft_strlen(tmp->group);
		links_len = ft_strlen(tmp->links);
		bytes_len = ft_strlen(tmp->bytes);

		if (pad->filepath < filepath_len)
			pad->filepath = filepath_len + 1;
		if (pad->owner_name < owner_name_len)
			pad->owner_name = owner_name_len;
		if (pad->group_name < group_name_len)
			pad->group_name = group_name_len;
		if (pad->links < links_len)
			pad->links = links_len;
		if (pad->bytes < bytes_len)
			pad->bytes = bytes_len;

		list = list->next;
	}
}

