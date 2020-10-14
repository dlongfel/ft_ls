/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:56:47 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:56:47 by richardbrac      ###   ########.fr       */
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
