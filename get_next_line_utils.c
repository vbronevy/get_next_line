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

// Helper function to read new data and append to the buffer
char *read_and_append(int fd, char *buffer)
{
    char *chunk = malloc(BUFFER_SIZE + 1);
    int bytes_read;

    if (!chunk)
        return (NULL);
    bytes_read = read(fd, chunk, BUFFER_SIZE);
    if (bytes_read < 0)  // Error
    {
        free(chunk);
        return (NULL);
    }
    chunk[bytes_read] = '\0';

    if (bytes_read == 0)  // EOF: Preserve buffer for last line
    {
        free(chunk);
        return (buffer);  // Return existing buffer (may be NULL)
    }

    char *new_buffer = ft_strjoin(buffer, chunk);  // Append read data to buffer
    free(chunk);
    free(buffer);  // Free old buffer after joining
    return (new_buffer);
}
int find_newline(char *str)
{
    int i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *extract_line(char *str, int len)
{
    char *line = malloc(len + 1);
    int i = 0;

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

char *trim_buffer(char *buffer, int start)
{
    int remaining_len = ft_strlen(buffer + start);
    char *new_buffer = NULL;

    if (remaining_len > 0)
        new_buffer = ft_strdup(buffer + start);
    free(buffer);
    return (new_buffer);
}
// // Helper function to extract a line (up to and including the first '\n')
// char *ft_substr_gnl(char *str, int len)
// {
//     char *substr;
//     int i;

//     if (!str || len < 0)
//         return (NULL);

//     substr = malloc(len + 1);
//     if (!substr)
//         return (NULL);

//     i = 0;
//     while (i < len)
//     {
//         substr[i] = str[i];
//         i++;
//     }
//     substr[i] = '\0';
//     return (substr);
// }



// int ft_strchr_gnl(char *str)
// {
//     int i = 0;

//     if (!str)
//         return (-1);

//     while (str[i])
//     {
//         if (str[i] == '\n')
//             return (i);
//         i++;
//     }
//     return (-1);
// }

char *ft_strdup(char *str)
{
    char *dup;
    size_t len = ft_strlen(str);

    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    for (size_t i = 0; i < len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return (dup);
}

// // Helper function to update buffer, removing the processed part (the line)
// char *update_buffer(char *buffer, int start)
// {
//     char *new_buffer;
//     int len;

//     if (!buffer)
//         return (NULL);

//     len = ft_strlen(buffer) - start;
//     if (len <= 0)
//     {
//         free(buffer);
//         return (NULL);
//     }

//     new_buffer = ft_strdup_gnl(buffer + start, len);
//     free(buffer);
//     return (new_buffer);
// }
size_t	ft_strlen(const char *s)
{
    size_t len = 0;

    while (s && s[len])
        len++;
    return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *result;
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);

    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);

    for (size_t i = 0; i < len1; i++)
        result[i] = s1[i];
    for (size_t j = 0; j < len2; j++)
        result[len1 + j] = s2[j];
    result[len1 + len2] = '\0';

    return (result);
}

