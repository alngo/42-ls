/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:00:49 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 13:43:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	ft_printf(" ");
}
