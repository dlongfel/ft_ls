/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:09:53 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/12 18:10:05 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int argc, char **argv)
{
	int			i;
	int			flags;
	int			nothing;
	t_file		*lst_file;

	if ((i = flags_parser(argc, argv, &flags)) == -1)
		return (1);
	argv += i;
	argc -= i;
	lst_file = initialization_file_list(argv, argc, 1);
	nothing = (!lst_file ? 1 : 0);
	display_all(lst_file, flags, (!nothing ? 1 : 2), argc);
	free_list_information(&lst_file);
	return (0);
}
