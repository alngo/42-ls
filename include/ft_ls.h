/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:22:37 by alngo             #+#    #+#             */
/*   Updated: 2019/10/16 16:36:10 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
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
	size_t		count;
	t_list		*other_list;
}			t_ls;

typedef struct		s_ls_arg
{
	struct stat 	stat;
	char		*name;
}			t_ls_arg;

void			usage_out(t_ls *ls);
void			illegal_option_out(t_ls *ls, char option);
void			ls_perror_out(t_ls *ls, char *name);

uint8_t			retrieve_options(char ***av, t_ls *ls);

t_list			*retrieve_arguments(char ***args, t_ls *ls);
void			add_to_list(t_list **list, t_list *newElement, t_ls *ls);

int			lexicographicalOrder(void *contentToInsert,
		void *content);
int			lexicographicalOrderInverted(void *contentToInsert,
		void *content);
int			sortByTime(void *contentToInsert, void *content);

// tmpDoDelete
void 			displayFileStat(const char *arg_name, struct stat *fileStat);
void	 		displayListOrder(t_list *list);

#endif
