/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:39:20 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:39:20 by dlongfel         ###   ########.fr       */
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
