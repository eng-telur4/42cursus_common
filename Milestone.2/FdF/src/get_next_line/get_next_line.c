/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:39:34 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/01 03:07:44 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		old_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (ft_strchr_index(buffer, '\n') == -1)
	{
		old_len = ft_strlen(buffer);
		buffer = ft_expand_buffer(buffer, fd);
		if (old_len == ft_strlen(buffer) && buffer)
			line = ft_substr(buffer, 0, ft_strlen(buffer));
	}
	if (!buffer)
		return (NULL);
	if (!line && ft_strchr_index(buffer, '\n') != -1)
		line = ft_substr(buffer, 0, ft_strchr_index(buffer, '\n') + 1);
	if (line)
	{
		buffer = ft_shrink_buffer(buffer, line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*ft_shrink_buffer(char *buffer, char *line)
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

// bufferの末尾にft_new_readでBUFFER_SIZEバイト読み込んだ文字列を追加する
char	*ft_expand_buffer(char *buffer, int fd)
{
	char	*new_buffer;
	int		new_len;
	char	*aux;

	aux = ft_new_read(fd);
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

// ファイルディスクリプタfdからBUFFER_SIZEバイトずつ読み込む
char	*ft_new_read(int fd)
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

// 文字列strの中で最初に文字cが現れるインデックスを返す
int	ft_strchr_index(const char *str, int c)
{
	unsigned char	ch;
	int				i;

	if (!str)
		return (-1);
	ch = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	if (ch == '\0')
		return (i);
	return (-1);
}
