/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:22:07 by lolaparr          #+#    #+#             */
/*   Updated: 2023/12/08 19:22:09 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_garbage
{
	void				*p;
	struct s_garbage	*next;
}			t_garbage;

typedef struct s_garbage_data
{
	t_garbage	*garbage;
}			t_garbage_data;

void			*ft_malloc(size_t size);
void			free_garbage(void);
t_garbage		*create_node(void *data);
t_garbage		*push_to_garbage(t_garbage *begin_list, void *data);
t_garbage_data	*_garbage(void);
#endif
