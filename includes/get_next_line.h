/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:58:54 by hrobin            #+#    #+#             */
/*   Updated: 2023/12/09 14:58:57 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "garbage.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buff_crumbs);
char	*ft_cut(char *buff_crumbs);
char	*ft_clean(char *buff_crumbs);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strchr(char *s, int c);

#endif
