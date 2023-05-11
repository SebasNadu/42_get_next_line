/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:36 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/11 17:04:38 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		c;
	int			n;
	char		*buff_start;

	buff_start = buff;
	n = read(fd, buff, BUFFER_SIZE);
	if (n == -1)
		return (NULL);
	return (buff);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	printf("line=> %s", str);
	return (0);
}
