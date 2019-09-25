/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:22:37 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 13:43:15 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

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

#endif
