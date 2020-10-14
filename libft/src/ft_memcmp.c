/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:35:59 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:36:00 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	if (!arr1 && !arr2)
		return (0);
	a = (char *)arr1;
	b = (char *)arr2;
	while (i < n)
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return ((unsigned char)a[i - 1] - (unsigned char)b[i - 1]);
}
