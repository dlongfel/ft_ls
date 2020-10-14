/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:54:59 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:55:00 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!dst && !ap)
		return (NULL);
	while (dst[i])
		i++;
	while (ap[j])
		dst[i++] = ap[j++];
	dst[i] = '\0';
	return (dst);
}
