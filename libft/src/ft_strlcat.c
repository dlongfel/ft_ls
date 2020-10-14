/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:38:16 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:38:17 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *ap, size_t n)
{
	size_t	s;

	s = ft_strlen(dst);
	if (n > s)
		ft_strncat(dst, ap, (n - s - 1));
	else if (n < s)
		return (n + ft_strlen(ap));
	return (s + ft_strlen(ap));
}
