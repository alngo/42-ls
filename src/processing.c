/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:44:47 by alngo             #+#    #+#             */
/*   Updated: 2019/11/06 11:46:35 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*retrieve_list(char *dirname, t_ls *ls)
{
	t_list		*list;
	t_list		*tmp;
	DIR		*dirp;
	struct dirent	*dp;
	char		*filepath;
	(void)tmp;

	list = NULL;
	if (!(dirp = opendir(dirname)))
		ls_perror_out(ls, dirname);
	else
		while((dp = readdir(dirp)) != NULL)
		{
			filepath = ft_strjoin(dirname, "/");
			filepath = ft_strjoin(filepath, dp->d_name);
			if ((tmp = return_element(filepath, dp->d_name)))
				insert_to_list(&list, tmp, ls);
			ft_strdel(&filepath);
		}
	return (list);
}

void			process_directory(t_list *list, t_ls *ls)
{
	t_list		*args;
	t_ls_arg	*tmp;

	if (ls->count)
		ft_printf("\n");

	if (!list && !ls->count)
	{
		args = retrieve_list(".", ls);
		process_list(args, ls);
		ft_printf("\n");
	}
	else
	{
		while (list)
		{
			tmp = (t_ls_arg *)list->content;
			if (S_ISDIR(tmp->stat.st_mode))
			{
				args = retrieve_list(tmp->filepath, ls);
				if (ls->count || ft_lstcount(list) > 1)
					ft_printf("%s:\n", tmp->name);
				process_list(args, ls);
				ft_printf("\n");
				if (ls->options & LS_OPT_RECURSIVE)
					process_directory(args, ls);
			}
			list = list->next;
		}
	}
}

void 			process_list(t_list *list, t_ls *ls)
{
	t_ls_padding	padding;

	padding.name = 0;
	padding.owner_name = 0;
	padding.group_name = 0;
	padding.bytes = 0;
	padding.links = 0;
	set_padding(list, &padding);
	while (list)
	{
		if (ls->options & LS_OPT_LONG_FORMAT)
		{
			print_long_format(list, &padding);
			ft_printf("\n");
		}
		else
			print_short_format(list, &padding);
		list = list->next;
		ls->count++;
	}
}

void			print_long_format(t_list *list, t_ls_padding *pad)
{
	t_ls_arg	*tmp;

	tmp = (t_ls_arg *)list->content;
	print_mode(tmp);
	print_chmod(tmp->stat);
	ft_printf("  ");
	print_nlinks(tmp, pad);
	ft_printf(" ");
	print_owner_name(tmp, pad);
	ft_printf("  ");
	print_group_name(tmp, pad);
	ft_printf("  ");
	print_bytes(tmp, pad);
	ft_printf("  ");
	print_mtime(tmp->stat);
	ft_printf(" ");
	print_name(tmp, pad);
}

void			print_short_format(t_list *list, t_ls_padding *pad)
{
	t_ls_arg	*tmp;

	tmp = (t_ls_arg *)list->content;
	print_name(tmp, pad);
	ft_printf(" ");
}
