/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:40:37 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/13 20:46:05 by johnavar         ###   ########.fr       */
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
	i = -1;
	j = -1;
	while (line[++i])
		new_line[i] = line[i];
	while (buff[++j] && buff[j] != '\n')
		new_line[i + j] = buff[j];
	new_line[i + j] = '\0';
	return (new_line);
}
