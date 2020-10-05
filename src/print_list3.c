/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:49:10 by xtheress          #+#    #+#             */
/*   Updated: 2020/08/01 01:07:51 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			lst_column(t_file *lst, t_index len_col,
								t_index maxlen, int flags)
{
	int				tmp_column;
	int				tmp_len;
	t_file			*lst_tmp;
	int				counter;

	counter = len_col.y;
	while (lst && counter--)
	{
		tmp_column = len_col.x;
		lst_tmp = lst->next;
		while (lst && tmp_column--)
		{
			display_name(lst, flags, maxlen.y);
			if (tmp_column)
				ft_putnchar(MAX(maxlen.x - ft_strlen(lst->name), 0), ' ');
			tmp_len = len_col.y;
			while (lst && tmp_len--)
				lst = lst->next;
		}
		ft_putchar('\n');
		lst = lst_tmp;
	}
	return (1);
}

int					lst_blocks_len(t_file *lst, int *total)
{
	int				maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(len(lst->st_blocks), maxlen);
		*total += lst->st_blocks;
		lst = lst->next;
	}
	return (maxlen);
}

static int			display_1(t_file *lst, int flags)
{
	t_index			maxlen;
	struct ttysize	ts;
	t_index			i;
	t_file			*tmp_lst;
	int				total;

	total = 0;
	maxlen.x = lst_maxlen(lst) + ((flags & LS_G) ? 1 : 4);
	maxlen.y = (flags & LS_S) ? lst_blocks_len(lst, &total) : 0;
	if (flags & LS_S)
		ft_printf(" total %d\n", total);
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = (!(flags & 128)) ? ts.ts_cols / (maxlen.x + maxlen.y) : 1;
	i.y = 0;
	tmp_lst = lst;
	while (tmp_lst)
	{
		++i.y;
		tmp_lst = tmp_lst->next;
	}
	if (!(flags & 128))
		i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	lst_column(lst, i, maxlen, flags);
	return (1);
}

int					display_list(t_file **lst, int flags)
{
	sort_list(lst, flags);
	if (!(flags & LS_L))
		display_1(*lst, flags);
	else
		display_l(*lst, flags);
	return (1);
}

int					free_list_information(t_file **lst)
{
	while (*lst)
	{
		free((*lst)->name);
		free(*lst);
		*lst = (*lst)->next;
	}
	return (1);
}
