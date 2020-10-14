/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:54:07 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:54:08 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*ch;

	ch = (char *)b;
	i = 0;
	while (i < len)
	{
		ch[i] = c;
		i++;
	}
	return (b);
}
