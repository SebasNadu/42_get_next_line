/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:45:49 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 15:54:03 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	free(str);
	return (str);
}

t_lines	*find_lst(t_lines *storage, int fd)
{
	while (storage != NULL)
	{
		if (storage->fd == fd)
			return (storage);
		storage = storage->next;
	}
	return (NULL);
}

t_lines	*ft_lstadd_back(t_lines	**storage, int fd)
{
	t_lines	*new_lst;
	t_lines	*tmp;

	new_lst = (t_lines *)malloc(sizeof(t_lines));
	if (!new_lst)
		return (NULL);
	new_lst->fd = fd;
	new_lst->bytes_read = 1;
	new_lst->next = NULL;
	if (!*storage)
	{
		*storage = new_lst;
		return (*storage);
	}
	tmp = *storage;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_lst;
	return (new_lst);
}

char	*get_next_line(int fd)
{
	static t_lines	*storage = NULL;
	t_lines			*tmp;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = find_lst(storage, fd);
	if (!tmp)
		tmp = ft_lstadd_back(&storage, fd);
	if (find_n(tmp->buff) >= 0)
		set_line(&line, &tmp);
	while (find_n(tmp->buff) == -1 && tmp->bytes_read > 0)
	{
		tmp->bytes_read = read(fd, tmp->buff, BUFFER_SIZE);
		if (tmp->bytes_read < 0)
			return (ft_free(line));
		if (tmp->bytes_read == 0)
			return (line);
		tmp->buff[tmp->bytes_read] = '\0';
		line = ft_join_line(line, tmp);
	}
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("get_next_line_test/test4.txt", O_RDONLY);
	fd2 = open("get_next_line_test/test2.txt", O_RDONLY);
	fd3 = open("get_next_line_test/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
