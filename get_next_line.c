/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vbronevy <vbronevy@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/11 12:25:50 by vbronevy		  #+#	#+#			 */
/*   Updated: 2025/03/15 13:22:20 by vbronevy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			newline_idx;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_append(fd, buffer);
	if (!buffer)
		return (NULL);
	newline_idx = find_newline(buffer);
	if (newline_idx >= 0)
	{
		line = extract_line(buffer, newline_idx + 1);
		buffer = trim_buffer(buffer, newline_idx + 1);
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

char	*trim_buffer(char *buffer, int index)
{
	char	*new_buffer;

	new_buffer = ft_strdup(buffer + index);
	free(buffer);
	return (new_buffer);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		result[len1 + j] = s2[j];
		j++;
	}
	result[len1 + len2] = '\0';
	return (result);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str[200];
// 	char	*string;
// 	int 	num;

// 	fd = open("test.txt", O_RDONLY);
// 	string = get_next_line(fd);
// 	printf("%s\n", string);
//	 free(string);
// 	string = get_next_line(fd);
// 	printf("%s", string);
//	 free(string);
// }
