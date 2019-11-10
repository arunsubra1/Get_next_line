/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:37:21 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/10 01:22:04 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_next_line(char **s, char **line, int fd)
{
	char			*tmp;
	char			*next;
	int				i;

	i = 0;
	if (!(next = ft_strchr(s[fd], '\n')))
	{
		if (!*s[fd])
			return (0);
		*line = ft_strdup(s[fd]);
		ft_memdel((void **)&s[fd]);
		return (1);
	}
	while (++next != '\0')
	{
		*line = ft_strsub(s[fd], i, next - s[fd] - 1);
		i = ft_strlen(next);
		tmp = ft_strdup(s[fd] + (next - s[fd]));
		free(s[fd]);
		s[fd] = ft_strdup(tmp);
		ft_memdel((void **)&tmp);
		return (1);
	}
	return (0);
}

/*
**	store contents of file into large string (buff)
*/

int					get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	static char		*str[FD_MAX];
	int				bytes_read;

	tmp = NULL;
	if (fd < 0 || fd > FD_MAX || !line || (read(fd, buff, 0) < 0))
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = ft_strnew(0);
		while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[bytes_read] = '\0';
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = ft_strdup(tmp);
			ft_memdel((void **)&tmp);
		}
		if (bytes_read < 0)
			return (-1);
	}
	return (ft_next_line(str, line, fd));
}
