/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:04 by hrobin          #+#    #+#             */
/*   Updated: 2023/01/03 18:56:36 by hrobin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrdst;

	ptrdst = (unsigned char *)dst;
	if (!dst && !src && n)
		return (NULL);
	while (n--)
		*ptrdst++ = *(unsigned char *)src++;
	return (dst);
}
