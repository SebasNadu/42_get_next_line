/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:36 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/11 20:51:13 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	static int	i = 0;
	static int	bytes_read = 0;
	int			llen;
	char		*line;

	llen = 0;
	if (i == bytes_read)
	{
		i = 0;
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
	}
	while (llen < bytes_read && buff[llen] != '\n')
	{
		llen++;
	}
	line = ft_set_line(buff, llen, &i);
	return (line);
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
