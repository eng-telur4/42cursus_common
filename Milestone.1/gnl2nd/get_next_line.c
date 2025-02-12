/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:54:29 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/13 04:05:57 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// gcc -D BUFFER_SIZE=1024 -o my_program my_program.c

char	*get_next_line(int fd)
{
	char	*ret;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	return (ret);
}
