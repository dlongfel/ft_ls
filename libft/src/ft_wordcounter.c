/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:57:23 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:57:24 by richardbrac      ###   ########.fr       */
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
