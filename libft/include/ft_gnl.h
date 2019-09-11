/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:24:01 by alngo             #+#    #+#             */
/*   Updated: 2017/10/12 19:30:06 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include <sys/types.h>
# include <sys/uio.h>

typedef struct				s_gnl
{
	int						fd;
	char					*str;
	int						ret;
	struct s_gnl			*next;
}							t_gnl;

int							gnl(int fd, char **line);

#endif
