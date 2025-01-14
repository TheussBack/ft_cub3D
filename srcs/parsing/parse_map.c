/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:56:43 by lolaparr          #+#    #+#             */
/*   Updated: 2023/12/07 19:56:45 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == ' ')
		return (1);
	return (0);
}

void	check_map(void)
{
	int		i;
	int		j;
	t_data	*data;

	data = _data();
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (j == 0)
			{
				while (data->map[i][j] == ' ')
					j++;
			}
			if (!is_map_char(data->map[i][j]))
				print_error("Error\nInvalid character in map\n");
			j++;
		}
		i++;
	}
}

void	check_if_closed(int i, int j)
{
	t_data	*data;

	data = _data();
	if (i != 0 && j != 0 && j != ft_strlen(data->map[i])
		&& i != len_of_map())
	{
		if (j + 1 == ft_strlen(data->map[i])
			|| j >= ft_strlen(data->map[i - 1])
			|| j >= ft_strlen(data->map[i + 1])
			|| data->map[i - 1][j] == ' '
			|| data->map[i + 1][j] == ' '
			|| data->map[i][j - 1] == ' '
			|| data->map[i][j + 1] == ' ')
			print_error("Error\nMap not closed\n");
	}
	else
		print_error("Error\nMap not closed\n");
}

void	is_map_closed(void)
{
	int		i;
	int		j;
	t_data	*data;

	data = _data();
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				check_if_closed(i, j);
			j++;
		}
		i++;
	}
}

void	parse_map(void)
{
	t_data	*data;

	data = _data();
	if (data->fd > 0)
	{
		manage_map();
		check_map();
		check_player();
		is_map_closed();
		close(data->fd);
	}
}
