/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:29:40 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:29:42 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_range(int min, int max)
{
	int		*x;
	int		i;
	int		a;

	if (max > min)
	{
		i = 0;
		a = min;
		x = malloc(sizeof(int) * (max - min));
		while (a < max)
		{
			x[i] = a;
			a++;
			i++;
		}
		return (x);
	}
	else
		return (NULL);
}
