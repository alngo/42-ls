/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:44:20 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 13:42:04 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_owner_name(uid_t uid)
{
	struct passwd	*tmp;

	tmp = getpwuid(uid);
	return (tmp->pw_name);
}

char		*get_group_name(gid_t gid)
{
	struct group 	*tmp;

	tmp = getgrgid(gid);
	return (tmp->gr_name);
}

char		*get_suffix(off_t size)
{
	if (size > 1e3)
		return ("k");
	else if (size > 1e6)
		return ("M");
	else if (size > 1e9)
		return ("G");
	else
		return ("B");
}

char		*get_bytes_formatted(off_t size)
{
	char	*tmp;
	char	*ret;
	char	*suffix;

	suffix = get_suffix(size);
	if (size > 1e3)
		size /= 1e3;
	else if (size > 1e6)
		size /= 1e6;
	else if (size > 1e9)
		size /= 1e9;
	tmp = ft_imaxtoa_base(size, 10, "0123456789abcdef");
	ret = ft_strjoin(tmp, suffix);
	free(tmp);
	return (ret);
}

char		*get_links_formatted(nlink_t nlink)
{
	char	*tmp;

	tmp = ft_imaxtoa_base(nlink, 10, "0123456789abcdef");
	return (tmp);
}
