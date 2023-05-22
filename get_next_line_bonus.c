/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:36 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/22 20:00:57 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

void	set_line(char **line, char *buff)
{
	after_n(buff);
	*line = ft_join_line(*line, buff);
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	buff[1000001][BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (find_n(buff[fd]) >= 0)
		set_line(&line, buff[fd]);
	while (find_n(buff[fd]) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buff[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(line));
		if (bytes_read == 0)
			return (line);
		buff[fd][bytes_read] = '\0';
		line = ft_join_line(line, buff[fd]);
	}
	return (line);
}
