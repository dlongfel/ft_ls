/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtheress <xtheress@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:50:14 by xtheress          #+#    #+#             */
/*   Updated: 2020/08/01 01:05:00 by xtheress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	str_index(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int			little_parse(char *str, int *flags)
{
	int		f;

	while (*(++str))
	{
		if ((f = str_index("alRrtdG1Ss", *str)) == -1)
			ls_error(str, USAGE);
		*flags |= (1 << f);
		if ((*str == 'l') || (*str == '1'))
			*flags &= (*str == 'l') ? ~LS_ONE : ~LS_L;
	}
	return (1);
}

int			flags_parser(int argc, char **argv, int *flags)
{
	int		i;

	*flags = 0;
	i = 0;
	while (++i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (argv[i][1] == '-' && argv[i][2])
			return (i + 1);
		if (!little_parse(argv[i], flags))
			return (-1);
	}
	return (i);
}
