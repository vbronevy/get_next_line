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

char	*get_next_line(int fd)
{
	static int	i;
	char		*c;

	i = 0;
	c = read_ft(fd);
	memset(c, 0, BUFFER_SIZE + 1);
	if (fd == -1)
		return NULL;
	while(i < BUFFER_SIZE)
	{
		c = read_ft(fd);
		if(c[i] == '\0' || c[i] == '\n')
			break ;
		free(c);
		i++;
	}
	// if(c[i] == '\n')
	// 	c[i + 1] = '\0';
	// else
	// 	c[i] = '\0';
	return (c);
}

int	main(void)
{
	int		fd;
	char	*str;
	int 	num;

	fd = open("test.txt", O_RDONLY);
	// num = read(fd, str, BUFFER_SIZE);
	// printf("%d\n", num);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// free(str);
}
