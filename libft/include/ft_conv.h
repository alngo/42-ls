/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:55:04 by alngo             #+#    #+#             */
/*   Updated: 2019/09/18 11:42:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# define ABS(x) x < 0 ? -x : x
# define MBASE 36

typedef struct		s_stoul
{
	const char		*digits;
	const char		*sd;
	const char		*sc;
	const char		*s1;
	char			sign;
	unsigned long	x;
}					t_stoul;

int					ft_atoi(const char *s);
long				ft_atol(const char *s);
long				ft_strtol(const char *s, char **end, int base);
unsigned long		ft_stoul(const char *s, char **end, int base);
unsigned long		ft_strtoul(const char *s, char **end, int base);
char				*ft_imaxtoa_base(intmax_t value, uint8_t base,\
		const char *cipher);
char				*ft_itoa(int n);

#endif
