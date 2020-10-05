/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:01:36 by xtheress          #+#    #+#             */
/*   Updated: 2020/08/01 21:26:27 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <grp.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <uuid/uuid.h>

# define LS_A	1
# define LS_L	2
# define LS_RR	4
# define LS_R	8
# define LS_T	16
# define LS_D	32
# define LS_G	64
# define LS_ONE 128
# define LS_SS	256
# define LS_S	512

enum	{ERRNO, USAGE, MALL_ERR};

typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;
typedef struct stat		t_stat;

typedef struct			s_file
{
	mode_t				mode;
	nlink_t				st_nlink;
	uid_t				st_uid;
	gid_t				st_gid;
	off_t				size;
	dev_t				st_rdev;
	time_t				time;
	blkcnt_t			st_blocks;
	long				ntime;
	char				*name;
	char				path_end[PATH_MAX];
	struct s_file		*next;
	t_list				list;
}						t_file;

typedef struct			s_index
{
	int					y;
	int					x;
}						t_index;

int						display_all(t_file *start, int flags, int first, int n);
int						display_l(t_file *lst, int flags);
void					ft_putnchar(int len, char c);
int						free_list_information(t_file **lst);
int						display_list(t_file **lst, int flags);
int						lst_blocks_len(t_file *lst, int *total);
void					display_name(t_file *l, int flags, int blocks_len);
int						l_items(t_file *file, int size[7], int flags);
int						str_size(t_file *file, int size[7], int *blocks);
int						len(int n);
int						sort_list(t_file **start, short flags);
t_file					*r_sort(t_file *lst);
t_file					*s_sort(t_file *lst);
int						flags_parser(int argc, char **argv, int *flags);
int						add_file(char path[PATH_MAX], char *name, t_file **lst);
int						ls_error(char *str, int error);
int						lst_maxlen(t_file *lst);
t_file					*swap(t_file *p1, t_file *p2);
t_file					*initialization_file_list(char **names_list,
													int argc, int first);
int						tab_sort(char **tab, int size,
									int (*function)(const char*, const char*));

#endif
