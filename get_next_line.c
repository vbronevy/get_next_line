/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:25:50 by vbronevy          #+#    #+#             */
/*   Updated: 2025/03/12 15:07:34 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static int	i;
	char		*c;

	i = 0;
	c = (char *)calloc(100, sizeof(char));
	if (fd == -1)
		return NULL;

	while (c[i] != '\n' || c[i] != '\0')
	{
		if (c[i] == '\n')
			break ;
		read(fd, c, BUFFER_SIZE);
		i++;
		// c++;
	}
	// read(fd, c, 12);
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
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
}
