/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:54:54 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:54:55 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sqrt(int nb)
{
	int		i;
	int		j;

	i = 0;
	while (i <= nb)
	{
		j = i * i;
		if (j == nb)
			return (i);
		else if (j < nb)
			i++;
		else
			return (0);
	}
	return (0);
}
