/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:07:48 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/30 13:03:50 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strend(char *str, int len)
{
	while (str[len])
		len++;
	return (len);
}

char	*ft_read(char *swap, size_t fd)
{
	char	*tmp;
	char	*buf;
	size_t	ret;

	buf = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(swap, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strdup(swap);
		if (swap)
			free(swap);
		swap = ft_strjoin(tmp, buf);
		if (tmp)
			free(tmp);
	}
	(buf) ? (free(buf)) : (0);
	return (swap);
}

int		get_next_line(int const fd, char **line)
{
	static char		*swap[256];
	char			*buf;
	size_t			start;

	buf = ft_strnew(0);
	if (fd == -1 || read(fd, buf, 0) == -1 || !line)
		return (-1);
	(buf) ? (free(buf)) : (0);
	(!swap[fd]) ? (swap[fd] = ft_strnew(BUFF_SIZE)) : (0);
	swap[fd] = ft_read(swap[fd], fd);
	if (ft_strchr(swap[fd], '\n'))
	{
		start = 0;
		while (swap[fd][start] != '\n')
			start++;
		*line = ft_strsub(swap[fd], 0, start);
		swap[fd] = ft_strsub(swap[fd], start + 1, ft_strend(swap[fd], start));
		return (1);
	}
	if (swap[fd][0] != '\0' && (*line = ft_strdup(swap[fd])))
	{
		ft_bzero(swap[fd], ft_strlen(swap[fd]));
		return (1);
	}
	return (0);
}
