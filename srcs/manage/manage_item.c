/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:56:25 by lolaparr          #+#    #+#             */
/*   Updated: 2023/12/08 18:32:58 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	manage_color(int element, char *s)
{
	t_data	*data;

	data = _data();
	if (element > 0)
		print_error("Error\nDouble declaration\n");
	s += 1;
	s = is_valid_item(s);
	data->nb_el++;
	return (parse_color(s));
}

char	*manage_item(char *element, char *s)
{
	t_data	*data;

	data = _data();
	if (element != NULL)
		print_error("Error\nDouble declaration\n");
	s += 2;
	data->nb_el++;
	return (is_valid_item(s));
}

void	manage_map(void)
{
	t_data	*data;
	char	*tmp_join;
	char	*tmp;
	int		i;

	data = _data();
	tmp_join = NULL;
	while (1)
	{
		i = 0;
		tmp = get_next_line(data->fd);
		if (tmp == NULL)
			print_error("Error\nNo map in file\n");
		while (tmp[i] && is_it_a_space(tmp[i]))
			i++;
		if (tmp[i])
			break ;
	}
	while (tmp != NULL)
	{
		tmp_join = ft_strjoin(tmp_join, tmp);
		tmp = get_next_line(data->fd);
	}
	data->map = all_buf_to_map(tmp_join, '\n');
}
