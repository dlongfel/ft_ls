/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:23:25 by xtheress          #+#    #+#             */
/*   Updated: 2020/07/29 22:30:26 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		full_path(char path[PATH_MAX], char *name,
							char path_end[PATH_MAX])
{
	int			i;

	i = -1;
	while (path[++i])
		path_end[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			path_end[i++] = '/';
	while (*name && i < PATH_MAX)
		path_end[i++] = *name++;
	if (i < PATH_MAX)
		path_end[i] = '\0';
	else
		errno = ENAMETOOLONG;
	return ((i < PATH_MAX) ? 1 : 0);
}

static t_file	*new_file(char path[PATH_MAX], char *name, t_stat *stat)
{
	t_file		*new;

	if (!(new = (t_file*)ft_memalloc(sizeof(t_file)))
	|| (!(new->name = ft_strdup(name))))
		ls_error(NULL, 2);
	new->mode = stat->st_mode;
	new->st_nlink = stat->st_nlink;
	new->st_uid = stat->st_uid;
	new->st_gid = stat->st_gid;
	new->size = stat->st_size;
	new->st_rdev = stat->st_rdev;
	new->time = stat->st_mtimespec.tv_sec;
	new->ntime = stat->st_mtimespec.tv_nsec;
	new->st_blocks = stat->st_blocks;
	full_path(path, name, new->path_end);
	new->next = NULL;
	return (new);
}

int				add_file(char path[PATH_MAX], char *name, t_file **lst)
{
	char		path_end[PATH_MAX];
	t_stat		stat;

	if (!(full_path(path, name, path_end)))
	{
		ls_error(name, 1);
		return (-1);
	}
	if (lstat(path_end, &stat) == -1)
		return (-1);
	if (!*lst)
		*lst = new_file(path, name, &stat);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = new_file(path, name, &stat);
	}
	return (1);
}
