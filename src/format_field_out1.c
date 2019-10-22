/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_field_out1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:00:01 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 13:02:50 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 			read_write_execute_out(struct stat filestat)
{
	ft_printf((S_ISDIR(filestat.st_mode)) ? "d" : "-");
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
}

void			number_of_links_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->links, arg->links);
}

void			owner_name_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->owner_name, arg->owner);
}

void			group_name_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->group_name, arg->group);
}

