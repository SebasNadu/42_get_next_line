/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:36 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 16:04:27 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (find_n(buff) >= 0)
	{
		after_n(buff);
		set_line(&line, buff);
	}
	while (find_n(buff) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(line));
		if (bytes_read == 0)
			return (line);
		buff[bytes_read] = '\0';
		line = ft_join_line(line, buff);
	}
	return (line);
}
