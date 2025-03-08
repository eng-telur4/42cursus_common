/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:39:34 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/08 23:17:20 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		old_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (!ft_strchr(buffer, '\n'))
	{
		old_len = ft_strlen(buffer);
		buffer = add_reads(buffer, fd);
		if (old_len == ft_strlen(buffer) && buffer)
			line = ft_substr(buffer, 0, ft_strlen(buffer));
	}
	if (!buffer)
		return (NULL);
	if (!line && ft_strchr(buffer, '\n'))
		line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	if (line)
	{
		buffer = cut_line(buffer, line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*cut_line(char *buffer, char *line)
{
	char	*new_buffer;
	int		line_len;

	if (!buffer || !line)
		return (buffer);
	line_len = ft_strlen(line);
	if ((int)ft_strlen(buffer) == line_len)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_substr(buffer, line_len, ft_strlen(buffer) - line_len);
	free(buffer);
	return (new_buffer);
}

char	*add_reads(char *buffer, int fd)
{
	char	*new_buffer;
	int		new_len;
	char	*aux;

	aux = new_read(fd);
	if (!aux)
		return (NULL);
	if (!aux[0])
	{
		free(aux);
		return (buffer);
	}
	if (!buffer)
		return (aux);
	new_len = ft_strlen(buffer) + ft_strlen(aux);
	new_buffer = malloc(new_len + 1);
	if (!new_buffer)
		return (NULL);
	ft_strlcpy(new_buffer, buffer, new_len + 1);
	ft_strlcat(new_buffer, aux, new_len + 1);
	free(buffer);
	free(aux);
	return (new_buffer);
}

char	*new_read(int fd)
{
	char	*aux;
	int		nbytes;

	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	nbytes = read(fd, aux, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(aux);
		return (NULL);
	}
	aux[nbytes] = '\0';
	return (aux);
}
