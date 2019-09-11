/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:58:19 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 15:21:51 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_PUT_H
# define LFT_PUT_H

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putmem(const void *ptr, size_t n);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnstr_fd(char *s, size_t n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);

#endif
