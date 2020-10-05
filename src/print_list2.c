/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:31:36 by xtheress          #+#    #+#             */
/*   Updated: 2020/08/01 21:40:19 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_name(t_file *l, int flags, int blocks_len)
{
	if (blocks_len)
	{
		ft_putnchar(MAX(blocks_len - len(l->st_blocks), 0), ' ');
		ft_printf("%d ", l->st_blocks);
	}
	if (flags & LS_G)
	{
		if (S_ISDIR(l->mode))
			ft_printf("\033[32m%s\033[1m", l->name);
		else
			ft_printf((S_IXUSR & l->mode) ? "\033[31m" : "%s", l->name);
	}
	else
		ft_printf("%s", l->name);
}

int			str_size(t_file *file, int size[7], int *blocks)
{
	int		l;

	size[5] = 3;
	size[6] = 3;
	while (file)
	{
		size[0] = MAX(len(file->st_blocks), size[0]);
		size[1] = MAX(len(file->st_nlink), size[1]);
		size[2] = MAX(ft_strlen(getpwuid(file->st_uid)->pw_name), size[2]);
		size[3] = MAX(ft_strlen(getgrgid(file->st_gid)->gr_name), size[3]);
		if (!S_ISCHR(file->mode))
			l = len(file->size);
		else
		{
			size[5] = MAX(len(major(file->st_rdev)), size[5]);
			size[6] = MAX(len(minor(file->st_rdev)), size[6]);
			l = size[5] + size[6] + 2;
		}
		size[4] = MAX(l, size[4]);
		*blocks += file->st_blocks;
		file = file->next;
	}
	size[5] = MAX(size[4] - size[6] - 1, size[5]);
	return (1);
}

int			display_l(t_file *lst, int flags)
{
	int	size[7];
	int	blocks;
	int	first;

	ft_bzero(size, sizeof(size));
	blocks = 0;
	first = 1;
	str_size(lst, size, &blocks);
	while (lst)
	{
		if (first == 1 && !(flags & LS_D))
		{
			ft_printf("total %d\n", blocks);
			first = 0;
		}
		l_items(lst, size, flags);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (1);
}
