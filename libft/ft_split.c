/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:06 by hrobin          #+#    #+#             */
/*   Updated: 2023/01/03 19:14:52 by hrobin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char *str, char charset)
{
	if (*str == charset)
		return (1);
	return (0);
}

static int	len_word(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(is_charset(str + i, charset)))
		i++;
	return (i);
}

static int	word_count(char *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		if (*str && is_charset(str, charset))
			str++;
		i = len_word(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*word_cpy(char *str, int size)
{
	char	*dest;

	dest = ft_malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = str[size];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		size;
	int		j;

	i = 0;
	size = word_count((char *)s, c);
	matrix = ft_malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		while (*s && is_charset((char *)s, c))
			s++;
		j = len_word((char *)s, c);
		matrix[i] = word_cpy((char *)s, j);
		if (matrix[i] == NULL)
			return (NULL);
		s += j;
		i++;
	}
	matrix[size] = 0;
	return (matrix);
}
