/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:00:49 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 13:09:30 by alngo            ###   ########.fr       */
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
			pad->filepath = filepath_len;
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

void 			process_list(t_list *list, t_ls *ls)
{
	t_ls_padding	padding;

	padding.filepath = 0;
	padding.owner_name = 0;
	padding.group_name = 0;
	padding.bytes = 0;
	padding.links = 0;
	set_padding(list, &padding);
	while (list)
	{
		if (ls->options & LS_OPT_LONG_FORMAT)
			long_format_out(list, &padding);
		else
			short_format_out(list, &padding);
		list = list->next;
	}
}

void			long_format_out(t_list *list, t_ls_padding *pad)
{
	t_ls_arg	*tmp;

	tmp = (t_ls_arg *)list->content;
	read_write_execute_out(tmp->stat);
	ft_printf("  ");
	number_of_links_out(tmp, pad);
	ft_printf(" ");
	owner_name_out(tmp, pad);
	ft_printf("  ");
	group_name_out(tmp, pad);
	ft_printf("  ");
	number_of_byte_out(tmp, pad);
	ft_printf("  ");
	date_last_modified_out(tmp->stat);
	ft_printf(" ");
	filepath_out(tmp, pad);
	ft_printf("\n");
}

void			short_format_out(t_list *list, t_ls_padding *pad)
{
	t_ls_arg	*tmp;

	tmp = (t_ls_arg *)list->content;
	filepath_out(tmp, pad);
}
