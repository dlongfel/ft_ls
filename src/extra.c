/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:49:40 by xtheress          #+#    #+#             */
/*   Updated: 2020/08/01 01:03:41 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*swap(t_file *p1, t_file *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

int			lst_maxlen(t_file *lst)
{
	int		maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(ft_strlen(lst->name), maxlen);
		lst = lst->next;
	}
	return (maxlen);
}

int			ls_error(char *str, int error)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*str, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrtdG1Ss] [file ...]", 2);
	}
	else if (error == ERRNO || error == MALL_ERR)
		ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else if (error == ERRNO)
		ft_putendl_fd(strerror(errno), 2);
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}

int			len(int n)
{
	int		l;

	l = 1;
	while (n / 10)
	{
		n /= 10;
		++l;
	}
	return (l);
}
