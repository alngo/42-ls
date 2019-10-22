/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_plain_field_out.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:09:26 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 12:31:26 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			filepath_out(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%-*s", pad->filepath, arg->filepath);
}

void 			read_write_execute_out(struct stat fileStat)
{
	ft_printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	ft_printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
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
