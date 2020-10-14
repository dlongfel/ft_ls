/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:17 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:30:17 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_wcharlen(*s);
		++s;
	}
	return (len);
}
