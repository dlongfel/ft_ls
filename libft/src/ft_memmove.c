/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:54:03 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:54:04 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	if (a > b)
	{
		while (i++ < len)
			a[len - i] = b[len - i];
	}
	else
	{
		while (len-- > 0)
			*a++ = *b++;
	}
	return (dst);
}
