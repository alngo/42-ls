/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:22:37 by alngo             #+#    #+#             */
/*   Updated: 2019/11/06 11:21:37 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>

typedef enum		e_ls_options
{
	LS_OPT_LONG_FORMAT = 0x01,
	LS_OPT_RECURSIVE = 0x02,
	LS_OPT_SHOW_HIDDEN = 0x04,
	LS_OPT_REVERSE_ORDER = 0x08,
	LS_OPT_SORT_BY_TIME = 0x10
}			t_ls_options;

typedef struct		s_ls
{
	char		*name;
	uint8_t		options;
	size_t		count;
}			t_ls;

typedef struct		s_ls_arg
{
	struct stat 	stat;
	char		*filepath;
	char		*name;
	char		*owner;
	char		*group;
	char		*links; //TOfree
	char		*bytes; //TOfree
}			t_ls_arg;

typedef struct		s_ls_padding
{
	int		name;
	int		owner_name;
	int		group_name;
	int		bytes;
	int		links;
}			t_ls_padding;

/*
**	retrieve_option.c
*/

void			retrieve_options(char ***av, t_ls *ls);

/*
**	retrieve_arguments.c
*/

void			retrieve_arguments(char ***args, t_ls *ls,
		t_list **directory_list, t_list **other_list);
void			insert_to_list(t_list **list,
		t_list *newElement, t_ls *ls);
t_list			*return_element(char *filepath, char *name);
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
**	processing.c
*/

void			process_directory(t_list *list, t_ls *ls);
void 			process_list(t_list *list, t_ls *ls);
void			print_long_format(t_list *list, t_ls_padding *pad);
void			print_short_format(t_list *list, t_ls_padding *pad);

/*
**	print_field1.c
*/

void			print_mode(struct stat filestat);
void 			print_chmod(struct stat filestat);
void			print_nlinks(t_ls_arg *arg, t_ls_padding *pad);
void			print_owner_name(t_ls_arg *arg, t_ls_padding *pad);
void			print_group_name(t_ls_arg *arg, t_ls_padding *pad);

/*
**	print_field2.c
*/

void			print_bytes(t_ls_arg *arg, t_ls_padding *pad);
void 			print_mtime(struct stat filestat);
void			print_name(t_ls_arg *arg, t_ls_padding *pad);

/*
**	print_error.c
*/

void			usage_out(t_ls *ls);
void			illegal_option_out(t_ls *ls, char option);
void			ls_perror_out(t_ls *ls, char *name);

/*
**	utils.c
*/

char			*get_owner_name(uid_t uid);
char			*get_group_name(gid_t gid);
char			*get_bytes_formatted(off_t size);
char			*get_links_formatted(nlink_t nlink);

/*
**	padding.c
*/

void			set_padding(t_list *list, t_ls_padding *pad);

#endif
