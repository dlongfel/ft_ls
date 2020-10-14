/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:53:38 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:53:39 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (a[i] == (unsigned char)c)
			return (&a[i + 1]);
		i++;
	}
	return (NULL);
}
