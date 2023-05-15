/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:36 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/14 15:12:47 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			bytes_read;
	int			llen;
	char		*line;
	char		*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0)
		return (line);
	buff[BUFFER_SIZE] = '\0';
	tmp = line;
	line = ft_join_line(line, buff);
	free(tmp);
	return (NULL);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	printf("line => %s\n", str);
	str = get_next_line(fd);
	printf("line2 => %s\n", str);
	close(fd);
	return (0);
}
