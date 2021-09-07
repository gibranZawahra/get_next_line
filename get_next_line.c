/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:59:09 by gizawahr          #+#    #+#             */
/*   Updated: 2020/01/27 14:05:34 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*str;

	if (!(str = malloc(size * nbr)))
		return (0);
	ft_bzero(str, nbr * size);
	return (str);
}

char	*remove_prev(char *rest, int i)
{
	char			*tmp;

	if (rest[i])
		tmp = ft_strdup(rest + i + 1);
	else
		tmp = NULL;
	free(rest);
	return (tmp);
}

int		free_return(int ret, char **p1, char **p2)
{
	if (ret >= 0 && (*p1 || *p2))
	{
		if (*p1)
			free(*p1);
		if (ret == 0 && *p2)
			free(*p2);
	}
	if (ret == ERROR)
	{
		if (!*p1)
			free(*p1);
		if (!*p2)
			free(*p2);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	int				ret;
	char			*buf;
	static char		*rest;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (i = 0) ||
			!(buf = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (free_return(ERROR, &buf, &rest));
	if (!rest)
		if (!(rest = (char *)ft_calloc(sizeof(char), 1)))
			return (free_return(ERROR, &buf, &rest));
	while (!ft_strchr(buf, '\n') && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == ERROR)
			return (free_return(ERROR, &buf, &rest));
		buf[ret] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	while (rest[i] && rest[i] != '\n')
		i++;
	*line = ft_substr(rest, 0, i);
	rest = remove_prev(rest, i);
	if (rest || ret)
		return (free_return(LINE, &buf, &rest));
	return (free_return(0, &buf, &rest));
}
