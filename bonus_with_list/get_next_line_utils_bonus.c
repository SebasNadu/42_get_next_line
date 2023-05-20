/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:54:16 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 15:47:07 by johnavar         ###   ########.fr       */
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

char	*ft_join_line(char *line, t_lines *tmp)
{
	int		i;
	int		j;
	char	*new_line;

	new_line = malloc(sizeof(char) * (ft_strlen(line) + tmp->bytes_read + 1));
	if (new_line)
	{
		i = -1;
		j = -1;
		while (line && line[++i])
			new_line[i] = line[i];
		if (i == -1)
			i = 0;
		while (++j < tmp->bytes_read - 1 && tmp->buff[j] != '\n')
			new_line[i + j] = tmp->buff[j];
		new_line[i + j] = tmp->buff[j];
		if ((j < tmp->bytes_read && tmp->buff[j] == '\n') || j == -1)
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	dest = (char *)dst;
	source = (char *)src;
	if (dest >= source)
	{
		while (len)
		{
			len--;
			*(dest + len) = *(source + len);
		}
		return (dst);
	}
	while (len)
	{
		*dest++ = *source++;
		len--;
	}
	return (dst);
}

void	set_line(char **line, t_lines **tmp)
{
	char	*tmp_src;
	int		i;

	i = 0;
	while ((*tmp)->buff[i] && (*tmp)->buff[i] != '\n')
		i++;
	if ((*tmp)->buff[i] && (*tmp)->buff[i] == '\n')
		i++;
	tmp_src = (*tmp)->buff + i;
	ft_memmove((*tmp)->buff, tmp_src, (*tmp)->bytes_read - (i - 1));
	*line = ft_join_line(*line, *tmp);
	if ((*line)[0] == '\0')
	{
		free(*line);
		*line = NULL;
		free(*tmp);
	}
}
