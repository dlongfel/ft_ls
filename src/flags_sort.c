/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:47:37 by xtheress          #+#    #+#             */
/*   Updated: 2020/07/30 23:53:52 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*s_sort(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->size < lst->next->size))
		lst = swap(lst, lst->next);
	lst->next = s_sort(lst->next);
	if (lst->next && (lst->size < lst->next->size))
	{
		lst = swap(lst, lst->next);
		lst->next = s_sort(lst->next);
	}
	return (lst);
}

static t_file	*t_sort(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->time < lst->next->time))
		lst = swap(lst, lst->next);
	else if (lst->next && lst->time == lst->next->time)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = swap(lst, lst->next);
	lst->next = t_sort(lst->next);
	if (lst->next && (lst->time < lst->next->time))
	{
		lst = swap(lst, lst->next);
		lst->next = t_sort(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = swap(lst, lst->next);
			lst->next = t_sort(lst->next);
		}
	}
	return (lst);
}

static t_file	*ascii_sort(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = swap(lst, lst->next);
	lst->next = ascii_sort(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = swap(lst, lst->next);
		lst->next = ascii_sort(lst->next);
	}
	return (lst);
}

t_file			*r_sort(t_file *lst)
{
	t_file *a;
	t_file *b;
	t_file *c;

	a = NULL;
	b = lst;
	c = (lst)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}

int				sort_list(t_file **start, short flags)
{
	*start = ascii_sort(*start);
	if (flags & LS_T)
		*start = t_sort(*start);
	if (flags & LS_SS)
		*start = s_sort(*start);
	if (flags & LS_R)
		*start = r_sort(*start);
	return (1);
}
