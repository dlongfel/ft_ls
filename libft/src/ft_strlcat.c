/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:55:52 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:55:53 by richardbrac      ###   ########.fr       */
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
