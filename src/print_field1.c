/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:45:21 by alngo             #+#    #+#             */
/*   Updated: 2019/11/06 10:54:33 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_mode(struct stat filestat)
{
	unsigned int	mode;

	mode = filestat.st_mode;
	if (S_ISFIFO(mode))
		ft_printf("p");
	else if (S_ISCHR(mode))
		ft_printf("c");
	else if (S_ISDIR(mode))
		ft_printf("d");
	else if (S_ISBLK(mode))
		ft_printf("b");
	else if (S_ISLNK(mode))
		ft_printf("l");
	else if (S_ISSOCK(mode))
		ft_printf("s");
	else
		ft_printf("-");
}

void 			print_chmod(struct stat filestat)
{
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

void			print_nlinks(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->links, arg->links);
}

void			print_owner_name(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->owner_name, arg->owner);
}

void			print_group_name(t_ls_arg *arg, t_ls_padding *pad)
{
	ft_printf("%*s", pad->group_name, arg->group);
}

