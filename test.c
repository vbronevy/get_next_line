/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-12 17:11:13 by vbronevy          #+#    #+#             */
/*   Updated: 2025-03-12 17:11:13 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	int fd, sz;
	char* c;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0) {
		perror("r1");
		exit(1);
	}
	c = (char*)calloc(100, sizeof(char));
	sz = read(fd, c, 20);
	printf("called read(% d, c, 10). returned that"
		   " %d bytes were read.\n",
		   fd, sz);
	c[sz] = '\0';
	printf("Those bytes are as follows: %s\n", c);

	free(c);
	return 0;
}