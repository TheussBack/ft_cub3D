/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:10 by hrobin          #+#    #+#             */
/*   Updated: 2023/01/03 18:56:37 by hrobin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*src;

	src = (char *)s;
	i = ft_strlen(s);
	while (i)
	{
		if (src[i] == (char)c)
			return (src + i);
		i--;
	}
	if (src[i] == (char)c)
		return (src + i);
	return (NULL);
}
