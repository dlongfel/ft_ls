/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:55:29 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:55:29 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*c;
	int		i;

	if (ft_strlen(str) > (ft_strlen(str) + 1))
		return (0);
	c = malloc(ft_strlen(str) + 1);
	i = 0;
	if (c)
	{
		while (str[i])
		{
			c[i] = str[i];
			i++;
		}
		c[i] = '\0';
		return (c);
	}
	else
		return (NULL);
}
