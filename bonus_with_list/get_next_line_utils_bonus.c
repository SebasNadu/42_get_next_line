/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:54:16 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/18 10:00:14 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_join_line(char *line, char *buff)
{
	int		i;
	int		j;
	char	*new_line;

	new_line = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buff) + 1));
	if (new_line)
	{
		i = -1;
		j = -1;
		while (line && line[++i])
			new_line[i] = line[i];
		if (i == -1)
			i = 0;
		while (buff && buff[++j] && buff[j] != '\n')
			new_line[i + j] = buff[j];
		new_line[i + j] = buff[j];
		if ((buff && buff[j] && buff[j] == '\n') || j == -1)
			j++;
		new_line[i + j] = '\0';
	}
	else
	{
		free(new_line);
		return (NULL);
	}
	free(line);
	return (new_line);
}

int	find_n(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	after_n(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] && buff[i] == '\n')
		i++;
	while (j < BUFFER_SIZE - i && buff[i + j])
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}

void	set_line(char **line, t_lines **tmp)
{
	after_n((*tmp)->buff);
	*line = ft_join_line(*line, (*tmp)->buff);
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		free(*tmp);
	}
}
