/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:02:31 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 16:32:04 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("get_next_line_test/fsoares/only_nl.txt", O_RDONLY);
	fd2 = open("get_next_line_test/fsoares/multiple_nl.txt", O_RDONLY);
	fd3 = open("get_next_line_test/fsoares/variable_nls.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		str = get_next_line(fd1);
		printf("line [%02d]: %s", i, str);
		free(str);
		str = get_next_line(fd2);
		printf("line [%02d]: %s", i, str);
		free(str);
		str = get_next_line(fd3);
		printf("line [%02d]: %s", i, str);
		free(str);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
