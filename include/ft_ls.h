/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:22:37 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 14:51:12 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>

# define LS_OPT_LONG_FORMAT 	0x01
# define LS_OPT_RECURSIVE 	0x02
# define LS_OPT_INCLUDE_DOT 	0x04
# define LS_OPT_REVERSE_ORDER 	0x08
# define LS_OPT_SORT_BY_TIME	0x10

typedef struct		s_ls
{
	char		*name;
	uint8_t		options;
}			t_ls;

typedef struct		s_directory
{

}			t_directory;

void		usage_out(t_ls *ls);
void		illegal_option_out(t_ls *ls, char option);
void		file_not_found_out(t_ls *ls, char *file_name);
void		permission_denied_out(t_ls *ls, char *file_name);

void		loop_through_options(char **av, t_ls *ls);

#endif
