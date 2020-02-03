/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:31:51 by alngo             #+#    #+#             */
/*   Updated: 2019/09/11 11:44:09 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_lstcount(t_list *lst);
t_list				*ft_lstat(t_list *lst, size_t n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstreverse(t_list *lst);
void				ft_lstadd(t_list **alst, t_list *newelem);
void				ft_lstaddafter(t_list **alst, t_list *newelem);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstinsert(t_list **alst, t_list *newelem,\
		int (*cmp)(void *, void *));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
