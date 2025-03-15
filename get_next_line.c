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

	i = 0;
	c = (char *)malloc(BUFFER_SIZE + 1);
	memset(c, 0, BUFFER_SIZE + 1);
	if (fd == -1)
		return NULL;
	while(i < BUFFER_SIZE)
	{
		read(fd, &c[i], 1);
		if(c[i] == '\0' || c[i] == '\n')
			break ;
		i++;
	}
	if(c[i] == '\n')
		c[i + 1] = '\0';
	else
		c[i] = '\0';
	return (c);
}

// int	main(void)
// {
// 	int		fd;
// 	char	str[BUFFER_SIZE];
// 	int 	num;

// 	fd = open("test.txt", O_RDONLY);
// 	num = read(fd, str, BUFFER_SIZE);
// 	printf("%d\n", num);
// 	// str = get_next_line(fd);
// 	// printf("%s\n", str);
// 	// free(str);
// 	// str = get_next_line(fd);
// 	// printf("%s\n", str);
// 	// free(str);
// }
