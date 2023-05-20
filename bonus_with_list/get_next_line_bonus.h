/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:52:39 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 15:53:36 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

typedef struct s_lines
{
	char			buff[BUFFER_SIZE + 1];
	int				fd;
	int				bytes_read;
	struct s_lines	*next;
}					t_lines;

char	*get_next_line(int fd);
int		ft_line_len(char *str, int *i);
char	*ft_join_line(char *line, t_lines *tmp);
int		ft_strlen(char *str);
int		find_n(char *str);
void	after_n(char *str);
void	set_line(char **line, t_lines **tmp);
char	*ft_free(char *str);

#endif
