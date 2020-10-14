/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:39:41 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:39:41 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcounter(char *str)
{
	int	i;
	int	counter;
	int	x;

	counter = 0;
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			i++;
			x = 1;
		}
		if (x == 1)
		{
			counter++;
			x = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	return (counter);
}
