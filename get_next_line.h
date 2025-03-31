/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:59:58 by vbronevy          #+#    #+#             */
/*   Updated: 2025/03/12 11:52:48 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char    *get_next_line(int fd);
char    *read_and_append(int fd, char *buffer);
int     find_newline(char *str);
char    *extract_line(char *str, int len);
char    *trim_buffer(char *buffer, int start);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *str);
size_t  ft_strlen(const char *s);

#endif