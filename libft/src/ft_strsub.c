/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:39:16 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:39:16 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ch;

	if (len > (len + 1))
		return (NULL);
	ch = (char *)malloc(sizeof(char) * len + 1);
	if (!s || !ch)
		return (NULL);
	ft_strncpy(ch, &s[start], len);
	ch[len] = '\0';
	return (ch);
}
