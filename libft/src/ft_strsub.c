/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:56:59 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:57:00 by richardbrac      ###   ########.fr       */
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
