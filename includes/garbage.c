/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:02:09 by hrobin            #+#    #+#             */
/*   Updated: 2023/12/09 15:02:12 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include "cub3d.h"

void	*ft_malloc(size_t size)
{
	t_garbage	*tmp;

	tmp = push_to_garbage(_garbage()->garbage, malloc(size));
	if (tmp == NULL)
	{
		free_garbage();
		return (NULL);
	}
	_garbage()->garbage = tmp;
	return (tmp->p);
}

t_garbage	*push_to_garbage(t_garbage *begin_list, void *data)
{
	t_garbage	*node_tmp;

	if (data == NULL)
		return (NULL);
	node_tmp = create_node(data);
	if (node_tmp == NULL)
	{
		free(data);
		return (NULL);
	}
	if (begin_list == NULL)
		return (node_tmp);
	else
	{
		node_tmp->next = begin_list;
		return (node_tmp);
	}
}

t_garbage	*create_node(void *data)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->p = data;
	return (node);
}

void	free_garbage(void)
{
	t_garbage	*garbage;
	t_garbage	*tmp;
	t_data		*data;

	data = _data();
	garbage = _garbage()->garbage;
	tmp = NULL;
	while (garbage)
	{
		tmp = garbage->next;
		free(garbage->p);
		free(garbage);
		garbage = tmp;
	}
	if (data->fd != -1)
		close(data->fd);
	exit(EXIT_SUCCESS);
	return ;
}

t_garbage_data	*_garbage(void)
{
	static t_garbage_data	data;

	return (&data);
}
