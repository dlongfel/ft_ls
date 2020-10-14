/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:53:43 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:53:43 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	ch = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (ch[i] == (unsigned char)c)
			return (&ch[i]);
		i++;
	}
	return (NULL);
}
