/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:06:09 by gizawahr          #+#    #+#             */
/*   Updated: 2020/01/27 14:06:51 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define LINE 1
# define ERROR -1
# define TRUE 1
# define FALSE 0

typedef int	t_bool;
int			get_next_line(int fd, char **line);
char		*ft_strchr(char *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
#endif
