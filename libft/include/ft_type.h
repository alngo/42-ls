/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:59:23 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 11:45:06 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

# define XA 0x200
# define XS 0x100
# define BB 0x80
# define CN 0x40
# define DI 0x20
# define LO 0x10
# define PU 0x8
# define SP 0x4
# define UP 0x2
# define XD 0x1
# define XI (DI | XD)
# define XO (LO | XD)
# define XP (UP | XD)

int		ft_ctype(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);
int		ft_isascii(int c);
int		ft_lower(int c);
int		ft_upper(int c);
void	ft_tolower(char *c);
void	ft_toupper(char *c);

#endif
