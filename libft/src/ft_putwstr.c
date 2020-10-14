/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:29:35 by dlongfel          #+#    #+#             */
/*   Updated: 2020/10/14 15:29:36 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *s)
{
	int		len;

	len = ft_wstrlen((unsigned *)s);
	(!len) ? write(1, "(null)", 6) : write(1, s, len);
	return ((!len) ? 6 : len);
}
