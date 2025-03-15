/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:25:50 by vbronevy          #+#    #+#             */
/*   Updated: 2025/03/15 13:22:20 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static int	i;
	char		*c;
	char		*holder;

	i = 0;
	c = (char *)malloc(BUFFER_SIZE);
	// c[0] = '\0';
	// holder = (char *)malloc(BUFFER_SIZE);
	if (fd == -1)
		return NULL;
	read(fd, c, BUFFER_SIZE);
	// while(&c[i] != '\n' || &c[i] != '\0')
	// {
	// 	read(fd, &c[i], 1);
	// 	i++;
	// }
	// free(holder);
	// holder[i] = '\0';
	return (c);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// free(str);
}
