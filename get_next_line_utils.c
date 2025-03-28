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
	char	*buffer;
	int		size;

	buffer = malloc(4092);
	size = read(fd, buffer, 4091);

	buffer[4091] = '\0';
	return (buffer);
}

char  *ft_substr_gnl(char *str, int index)
{
	char	*substr;
	int		i;

	substr = malloc(index + 2);
	while(str[i])
	{
		str[i] = substr[i];
		if(str[i] == '\n')
			break;
		i++;
	}
	str[i + 1] = '\0';
	return(substr);
}

int ft_strchr_gnl(char *str)
{
	int	index;

	index = 0;
	while(str[index])
	{
		if(str[index] == '\n')
			break;
		index++;
	}
	return(index);
}