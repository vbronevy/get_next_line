/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vbronevy <vbronevy@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/12 00:59:18 by vbronevy		  #+#	#+#			 */
/*   Updated: 2025/04/01 20:22:42 by vbronevy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_chunk_and_append(int fd, char *buffer, int *bytes_read)
{
	char	*chunk;
	char	*new_buffer;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
	{
		free(buffer);
		return (NULL);
	}
	*bytes_read = read(fd, chunk, BUFFER_SIZE);
	if (*bytes_read < 0)
	{
		free(chunk);
		free(buffer);
		return (NULL);
	}
	chunk[*bytes_read] = '\0';
	new_buffer = ft_strjoin(buffer, chunk);
	free(chunk);
	free(buffer);
	return (new_buffer);
}

static char	*cleanup_empty_buffer(char *buffer)
{
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*read_and_append(int fd, char *buffer)
{
	int	bytes_read;

	if (find_newline(buffer) != -1)
		return (buffer);
	while (1)
	{
		buffer = read_chunk_and_append(fd, buffer, &bytes_read);
		if (!buffer)
			return (NULL);
		if (bytes_read == 0 || find_newline(buffer) != -1)
			break ;
	}
	return (cleanup_empty_buffer(buffer));
}

int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char *str, int len)
{
	char	*line;
	int		i;

	line = malloc(len + 1);
	i = 0;
	if (!line)
		return (NULL);
	while (i < len && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
