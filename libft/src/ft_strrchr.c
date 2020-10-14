/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:39:03 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:39:03 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*b;

	b = (char *)str;
	i = (int)ft_strlen(str);
	if (ch == '\0')
		return (&b[ft_strlen(str)]);
	while (i >= 0)
	{
		if (b[i] == ch)
			return (&b[i]);
		i--;
	}
	return (NULL);
}
