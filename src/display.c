/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 23:20:23 by xtheress          #+#    #+#             */
/*   Updated: 2020/07/31 02:34:28 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*read_folder(char path[PATH_MAX], char *name, int options)
{
	t_file			*start;
	DIR				*folder;
	struct dirent	*entry;

	start = NULL;
	if (!(folder = opendir(path)))
		ls_error(name, 0);
	else if (!(options & LS_D))
	{
		while ((entry = readdir(folder)))
			if (entry->d_name[0] != '.' || (options & LS_A))
				add_file(path, entry->d_name, &start);
	}
	else
		add_file(path, ".", &start);
	if (folder)
		closedir(folder);
	return (start);
}

static void		display_path(char *path_end, int number, int *first)
{
	if (number != 0 && number != 1)
	{
		if (*first == 2)
		{
			*first = 1;
			ft_printf("%s:\n", path_end);
		}
		else
			ft_printf("\n%s:\n", path_end);
	}
}

int				display_all(t_file *start, int flags, int first, int n)
{
	t_file			*file;

	file = start;
	if (!(flags & LS_RR) && !first)
		return (1);
	while (file)
	{
		if (S_ISDIR(file->mode) && (first || (ft_strcmp(file->name, ".")
										&& ft_strcmp(file->name, ".."))))
		{
			display_path(file->path_end, n, &first);
			start = read_folder(file->path_end, file->name, flags);
			if (start)
			{
				display_list(&start, flags);
				display_all(start, flags, 0, -1);
				free_list_information(&start);
			}
		}
		file = file->next;
	}
	return (1);
}
