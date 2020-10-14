/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:57:03 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:57:04 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t'))
		a++;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (i >= a))
		i--;
	if (i == a)
		return (ft_strnew(1));
	return (ft_strsub(s, a, i - a + 1));
}
