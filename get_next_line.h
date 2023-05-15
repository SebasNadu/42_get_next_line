/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:14:20 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/15 15:52:44 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/*# define BUFFER_SIZE 1024*/

char	*get_next_line(int fd);
int		ft_line_len(char *str, int *i);
char	*ft_join_line(char *line, char *buff);
int		ft_strlen(char *str);
int		find_n(char *str);
void	after_n(char *str);

#endif
