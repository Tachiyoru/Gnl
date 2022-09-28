/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:05:22 by sleon             #+#    #+#             */
/*   Updated: 2022/06/27 13:08:49 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *line)
{
	char	*buff;
	int		byte_readed;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	byte_readed = 1;
	while (!ft_strchr(line, '\n') && byte_readed != 0)
	{
		byte_readed = read(fd, buff, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte_readed] = '\0';
		line = ft_strjoin(line, buff);
	}
	free (buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = ft_read_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	buff = ft_line_to_buff(line[fd]);
	line[fd] = ft_read_new_line(line[fd]);
	return (buff);
}
