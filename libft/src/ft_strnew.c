/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:56:37 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:56:38 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ch;

	if (size > (size + 1))
		return (NULL);
	ch = (char *)malloc(size + 1);
	if (!ch)
		return (NULL);
	ft_memset(ch, '\0', size + 1);
	return (ch);
}
