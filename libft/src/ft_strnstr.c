/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:56:42 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:56:42 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		a;

	i = 0;
	if (ft_strlen((char *)str2) == 0)
		return ((char *)&str1[0]);
	while (str1[i] && i < len)
	{
		j = 0;
		a = i;
		if (str1[i] == str2[j])
		{
			while (str2[j] && str1[i] && str1[i] == str2[j] && (i < len))
			{
				i++;
				j++;
			}
			if (str2[j] == '\0')
				return ((char *)&str1[i - j]);
		}
		i = a;
		i++;
	}
	return (NULL);
}
