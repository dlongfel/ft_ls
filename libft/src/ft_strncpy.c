/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:56:27 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:56:28 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i != n)
	{
		if (src[i] == '\0')
		{
			while (i != n)
			{
				dest[i] = '\0';
				i++;
			}
			return (dest);
		}
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
