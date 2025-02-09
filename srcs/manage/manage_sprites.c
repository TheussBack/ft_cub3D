/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:36:16 by lolaparr          #+#    #+#             */
/*   Updated: 2023/12/08 18:36:18 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**parse_sprites(char *pixel)
{
	int		i;
	int		j;
	int		k;
	int		**tab;
	t_data	*data;

	data = _data();
	i = 0;
	k = 0;
	tab = ft_malloc(sizeof(int *) * 512);
	while (i < 512)
	{
		j = 0;
		tab[i] = ft_malloc(sizeof(int) * 512);
		while (j < 512)
		{
			tab[i][j] = translate_color((unsigned char)pixel[k + 2],
					(unsigned char)pixel[k + 1], (unsigned char)pixel[k]);
			k += 4;
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (tab);
}

int	**open_sprites(char *path)
{
	t_data	*data;
	int		x;
	int		y;

	data = _data();
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&x, &y);
	if (!data->img.img_ptr)
	{
		printf("Error\nFailed to open sprite\n");
		close_window(0);
	}
	if (x != 512 || y != 512)
	{
		printf("Error\nWrong sprite size\n");
		close_window(0);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, \
			&data->img.len, &data->img.endian);
	return (parse_sprites(data->img.addr));
}

void	manage_sprites(void)
{
	t_data	*data;

	data = _data();
	data->w = 1620;
	data->h = 1080;
	init_mlx_ptr();
	data->no_sprite = open_sprites(data->no);
	data->so_sprite = open_sprites(data->so);
	data->we_sprite = open_sprites(data->we);
	data->ea_sprite = open_sprites(data->ea);
	data->img.img_ptr = NULL;
}
