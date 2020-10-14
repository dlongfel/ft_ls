/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:56:15 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:56:17 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *ap, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst && !ap)
		return (NULL);
	while (dst[i])
		i++;
	while (ap[j] && j < n)
		dst[i++] = ap[j++];
	dst[i] = '\0';
	return (dst);
}
