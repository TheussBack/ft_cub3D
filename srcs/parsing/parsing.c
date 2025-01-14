/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:57:06 by lolaparr          #+#    #+#             */
/*   Updated: 2023/12/07 19:57:08 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_it_a_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	check_extension(char *path)
{
	if (!ft_strcmp(ft_strnstr(path, ".cub", ft_strlen(path)), ".cub"))
		return (1);
	return (0);
}

void	parsing(void)
{
	t_data	*data;

	data = _data();
	data->path = is_valid_item(data->path);
	if (data->path != NULL && check_extension(data->path))
	{
		data->fd = open(data->path, O_RDONLY);
		if (data->fd > 0)
		{
			parse_item();
			parse_map();
			manage_sprites();
			return ;
		}
	}
	print_error("Error\nInvalid path\n");
}
