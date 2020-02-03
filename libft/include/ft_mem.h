/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:08:18 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 11:41:27 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

void		*ft_memset(void *dst, int c, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		ft_bzero(void *dst, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);

#endif
