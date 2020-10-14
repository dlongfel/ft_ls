/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:53:24 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:53:25 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lstclear(t_list *lst)
{
	while (lst)
	{
		free(lst->content);
		lst = lst->next;
	}
	free(lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*res;
	t_list		*a;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	if (!(res = ft_lstnew(list->content, list->content_size)))
		return (NULL);
	lst = lst->next;
	a = res;
	while (lst)
	{
		list = f(lst);
		if (!(a->next = ft_lstnew(list->content, list->content_size)))
		{
			lstclear(res);
			return (NULL);
		}
		a = a->next;
		lst = lst->next;
	}
	return (res);
}
