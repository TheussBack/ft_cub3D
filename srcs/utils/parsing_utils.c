/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:57:00 by lolaparr          #+#    #+#             */
/*   Updated: 2023/12/07 19:57:02 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*split_string_by_non_empty_lines(char *s)
{
	int		i;

	while (1)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				break ;
			if (is_it_a_space(s[i]))
				i++;
			else
				break ;
		}
		if (s[i] == '\n')
		{
			while (i >= 0)
			{
				s++;
				i--;
			}
		}
		else
			return (s);
	}
}

void	print_error(char *s)
{
	printf("%s", s);
	free_garbage();
}

void	check_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				print_error("Error\nInvalid declaration\n");
			j++;
		}
		i++;
	}
}

int	len_of_map(void)
{
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	while (data->map[i])
		i++;
	return (i - 1);
}
