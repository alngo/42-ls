/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:07:02 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 13:27:04 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>

# define SPF 	1
# define PL		2
# define MI 	4
# define SH 	8
# define ZE 	16
# define TY_H 	1
# define TY_HH 	2
# define TY_L 	3
# define TY_LL 	4
# define TY_J 	5
# define TY_Z 	6
# define WCHAR_07BITS 0x0
# define WCHAR_11BITS 0xC080
# define WCHAR_16BITS 0xE08080
# define WCHAR_21BITS 0xF0808080

typedef struct		s_wchart
{
	wchar_t			all;
	int				len;
	unsigned char	c;
}					t_wchart;

typedef struct		s_arg
{
	uintmax_t		n;
	intmax_t		nb;
	char			*s;
	char			spec;
	char			dot;
	size_t			width;
	size_t			prec;
	short			flags;
	short			type;
	size_t			length;
	size_t			limit;
	size_t			tmp;
	char			warn;
	char			att;
	int				wild;
}					t_arg;

void				miniprintf(const char *fmt, ...);
int					ft_printf(const char *fmt, ...);
int					ft_xprintf(const char *fmt, va_list *args, int fd);
int					isspec(char c, t_arg *arg);
int					isparsable(char c);
void				pad(char c, size_t n, size_t *len);
void				push_tmp(char *tmp, t_arg *arg, size_t *len, size_t size);
char				*parse(const char *s, t_arg *arg, va_list *ap);
char				*ft_litob(uintmax_t n, t_arg *arg, int base, char *s);
int					handle_percent(t_arg *arg, size_t *len);
int					handle_character(t_arg *arg, va_list *ap, size_t *len);
int					handle_string(t_arg *arg, va_list *ap, size_t *len);
int					handle_decimal(t_arg *arg, va_list *ap, size_t *len);
int					handle_pointer(t_arg *arg, va_list *ap, size_t *len);
int					handle_hexadecimal(t_arg *arg, va_list *ap, size_t *len);
int					handle_octal(t_arg *arg, va_list *ap, size_t *len);
int					handle_unsigned(t_arg *arg, va_list *ap, size_t *len);
int					handle_binary(t_arg *arg, va_list *ap, size_t *len);
int					handle_upper(t_arg *arg, va_list *ap, size_t *len);
int					xseg_wchart(t_wchart *w, wchar_t c);

#endif
