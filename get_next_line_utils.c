/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:40:37 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/11 20:41:06 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_line_len(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0' && str[index] != '\n')
		index++;
	return (index);
}

char	*ft_set_line(char buff[], int line_len, int *i)
{
	char	*line;
	int		j;

	j = 0;
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (j < line_len)
	{
		line[j++] = buff[*i];
		*i += 1;
	}
	line[j] = '\0';
	*i += 1;
	return (line);
}
