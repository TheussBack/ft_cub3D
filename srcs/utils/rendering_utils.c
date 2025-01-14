/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:21:29 by hrobin          #+#    #+#             */
/*   Updated: 2023/01/14 02:21:54 by hrobin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_floor_ceiling(void)
{
	t_data	*data;
	int		x;
	int		y;

	data = _data();
	x = 0;
	y = 0;
	while (x < data->w)
	{
		y = 0;
		while (y < data->h)
		{
			if (y < data->h / 2)
				img_pixel_put(x, y, data->ceiling);
			else
				img_pixel_put(x, y, data->floor);
			y++;
		}
		x++;
	}
	return (1);
}
