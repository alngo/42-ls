/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:22:37 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 10:44:47 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>

typedef enum		e_ls_options
{
	LS_OPT_LONG_FORMAT = 0x01,
	LS_OPT_RECURSIVE = 0x02,
	LS_OPT_INCLUDE_DOT = 0x04,
	LS_OPT_REVERSE_ORDER = 0x08,
	LS_OPT_SORT_BY_TIME = 0x10
}			t_ls_options;

typedef struct		s_ls
{
	char		*name;
	uint8_t		options;
}			t_ls;

typedef struct		s_ls_arg
{
	struct stat 	stat;
	char		*name;
	char		*owner;
	char		*group;
}			t_ls_arg;

typedef struct		s_ls_padding
{
	int		filepath;
	int		owner_name;
	int		group_name;
	int		bytes;
	int		links;
}			t_ls_padding;

/*
**	error_out.c
*/
void			usage_out(t_ls *ls);
void			illegal_option_out(t_ls *ls, char option);
void			ls_perror_out(t_ls *ls, char *name);
/*
**	retrieve_option.c
*/
void			retrieve_options(char ***av, t_ls *ls);
/*
**	retrieve_arguments.c
*/
void			retrieve_arguments(char ***args, t_ls *ls,
		t_list **directory_list, t_list **other_list);
void			add_to_list(t_list **list, t_list *newElement, t_ls *ls);
/*
**	sort_arguments.c
*/
int			lexicographicalOrder(void *contentToInsert,
		void *content);
int			lexicographicalOrderInverted(void *contentToInsert,
		void *content);
int			sortByTime(void *contentToInsert, void *content);
/*
**	format_out.c
*/
void			long_format_out(t_list *list, t_ls_padding *pad);
void			short_format_out(t_list *list, t_ls_padding *pad);
void 			process_list(t_list *list, t_ls *ls);
/*
**	long_plain_field_out.c
*/
void 			read_write_execute_out(struct stat fileStat);
void			number_of_links_out(struct stat fileStat, t_ls_padding *pad);
void			owner_name_out(t_ls_arg *arg, t_ls_padding *pad);
void			group_name_out(t_ls_arg *arg, t_ls_padding *pad);
void			filepath_out(t_ls_arg *arg, t_ls_padding *pad);
/*
**	long_formatted_field_out.c
*/
void			number_of_byte_out(struct stat fileStat);
void			month_day_last_modified_out(struct stat fileStat);
void			hour_minute_last_modified_out(struct stat fileStat);
/*
**	utils.c
*/
char			*get_owner_name(uid_t uid);
char			*get_group_name(gid_t gid);


// tmpDoDelete
void 			displayFileStat(const char *arg_name, struct stat *fileStat);
void	 		displayListOrder(t_list *list);

#endif
