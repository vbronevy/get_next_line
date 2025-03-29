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
	if (fd == -1)
		return NULL;
	i = ft_strchr_gnl(c);
	free(c);
	c = ft_substr_gnl(c,i);
	return (c);
}

int	main(void)
{
	int		fd;
	char	*str[200];
	char	*string;
	int 	num;

	fd = open("test.txt", O_RDONLY);
	string = get_next_line(fd);
	printf("%s\n", string);
	string = get_next_line(fd);
	printf("%s\n", string);
	string = get_next_line(fd);
	printf("%s\n", string);
	free(string);
}
