/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:36 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/17 09:41:04 by johnavar         ###   ########.fr       */
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
/*
int	main(void)
{
	char	*str;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("get_next_line_test/test.txt", O_RDONLY);
	fd2 = open("get_next_line_test/test2.txt", O_RDONLY);
	fd3 = open("get_next_line_test/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		str = get_next_line(fd1);
		printf("line [%02d]: %s", i, str);
		free(str);
		str = get_next_line(fd2);
		printf("line [%02d]: %s", i, str);
		free(str);
		str = get_next_line(fd3);
		printf("line [%02d]: %s", i, str);
		free(str);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
