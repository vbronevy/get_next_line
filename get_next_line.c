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

char *get_next_line(int fd)
{
    static char *buffer = NULL;  // Static buffer to hold leftover data
    char *line = NULL;
    int newline_idx;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = read_and_append(fd, buffer);  // Read new data into buffer
    if (!buffer)
        return (NULL);  // No data left or error

    newline_idx = find_newline(buffer);
    if (newline_idx >= 0)  // If a newline exists
    {
        line = extract_line(buffer, newline_idx + 1);  // Copy up to and including '\n'
        buffer = trim_buffer(buffer, newline_idx + 1); // Update buffer to remaining data
    }
    else  // No newline: return entire buffer as last line
    {
        line = ft_strdup(buffer);  // Duplicate remaining data
        free(buffer);
        buffer = NULL;
    }

    return (line);  // Return the line (ends at \n or \0)
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
//     free(string);
// 	string = get_next_line(fd);
// 	printf("%s\n", string);
//     free(string);
// 	string = get_next_line(fd);
// 	printf("%s\n", string);
//     free(string);
//     string = get_next_line(fd);
// 	printf("%s\n", string);
//     free(string);
// }
