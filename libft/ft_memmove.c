/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:04 by hrobin          #+#    #+#             */
/*   Updated: 2023/01/03 18:56:36 by hrobin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		s += len;
		d += len;
		while (len--)
			*--d = *--s;
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
