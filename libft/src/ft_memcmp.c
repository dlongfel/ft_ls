/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:53:48 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:53:50 by richardbrac      ###   ########.fr       */
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
