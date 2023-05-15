/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:40:37 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/15 15:48:48 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	i = ft_strlen(line);
	j = ft_strlen(buff);
	new_line = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (buff && buff[j] && buff[j] != '\n')
	{
		new_line[i + j] = buff[j];
		j++;
	}
	new_line[i + j] = '\0';
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
	while (buff && buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] && buff[i] == '\n')
		i++;
	if (buff[i] == '\0')
		return ;
	while (buff[i + j])
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}
