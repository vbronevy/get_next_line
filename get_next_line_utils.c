/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:59:18 by vbronevy          #+#    #+#             */
/*   Updated: 2025/03/12 01:07:10 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_ft(int fd)
{
	char*	str;
	int		size;

	str = malloc(BUFFER_SIZE + 1);
	size = read(fd, str, BUFFER_SIZE);
	if(!str)
		return (NULL);
	str[BUFFER_SIZE + 1] = '\0';
	return (str);
}
