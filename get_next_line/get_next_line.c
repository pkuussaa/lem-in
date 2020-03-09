/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:10:29 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/11 16:11:09 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	read_line(char **dst, char **line)
{
	int i;

	i = 0;
	while (dst[0][i] != '\n' && dst[0][i] != '\0')
		i++;
	if (dst[0][i] == '\n')
	{
		*line = ft_strsub(*dst, 0, i);
		ft_memmove(*dst, &((*dst)[i + 1]), ft_strlen(&((*dst)[i])));
	}
	else
	{
		*line = ft_strsub(*dst, 0, i);
		ft_strdel(&(*dst));
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static	char	*dst[MAX_FD];
	char			*str;

	if (BUFF_SIZE < 1 || fd < 0 || fd > MAX_FD)
		return (-1);
	if (dst[fd] == NULL)
		dst[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(dst[fd], buf);
		free(dst[fd]);
		dst[fd] = str;
		if ((ft_strchr(dst[fd], '\n')))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (dst[fd] == NULL || dst[fd][0] == '\0'))
		return (0);
	return (read_line(&dst[fd], line));
}
