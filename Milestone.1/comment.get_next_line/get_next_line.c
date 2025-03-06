/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:39:34 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/06 22:24:42 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @fn get_next_line
 * @brief ファイルディスクリプタから1行読み込む関数
 * @param fd ファイルディスクリプタ
 * @return 1行の文字列
 * @details This function reads a line from a file descriptor.
 * It returns the line that has been read from the file descriptor.
 * The function returns NULL if an error occurs.
 */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		old_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	// バッファ内に改行文字がない場合
	if (!ft_strchr(buffer, '\n'))
	{
		// バッファの現在の長さを取得
		old_len = ft_strlen(buffer);
		// バッファを拡張して新しいデータを読み込む
		buffer = add_reads(buffer, fd);
		// バッファの長さが変わらない場合（つまり、新しいデータが読み込まれなかった、ファイルに残ってる情報がない場合）
		if (old_len == ft_strlen(buffer) && buffer)
			// バッファ全体をlineにコピー
			line = ft_substr(buffer, 0, ft_strlen(buffer));
	}
	// バッファが空の場合
	if (!buffer)
		return (NULL);
	// lineがNULLで、バッファ内に改行文字がある場合
	if (!line && ft_strchr(buffer, '\n'))
		// 改行文字までの部分をlineにコピー
		line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	// lineがNULLでない場合
	if (line)
	{
		// バッファからlineの部分を削除
		buffer = cut_line(buffer, line);
		return (line); // lineを返す
	}
	// 再帰的に次の行を取得
	return (get_next_line(fd));
}

/**
 * @fn cut_line
 * @brief バッファからlineを削除する関数
 * @param buffer バッファ
 * @param line 削除する文字列
 * @return 新しいバッファ
 * @details This function removes line from the buffer.
 * It returns the new buffer.
 * The function returns NULL if the buffer or line is NULL.
 */
char	*cut_line(char *buffer, char *line)
{
	char	*new_buffer;
	int		line_len;

	// bufferかlineがNULLの場合は、bufferをそのまま返す(get_next_lineでbufferとlineのNULLチェックをしているため、ここには来ない)
	// if (!buffer || !line)
	// return (buffer);
	// lineの長さを取得
	line_len = ft_strlen(line);
	// bufferの長さがlineの長さと等しい場合(つまり、bufferが空になる場合)、NULLを返す
	if ((int)ft_strlen(buffer) == line_len)
	{
		free(buffer);
		return (NULL);
	}
	// bufferからlineの部分を削除した新しいバッファを作成
	new_buffer = ft_substr(buffer, line_len, ft_strlen(buffer) - line_len);
	free(buffer);
	return (new_buffer);
}

// bufferの末尾にnew_readでBUFFER_SIZEバイト読み込んだ文字列を追加する
/**
 * @fn add_reads
 * @brief ファイルから読み取ったデータをバッファに追加する関数
 * @param buffer バッファ
 * @param fd ファイルディスクリプタ
 * @return バッファに追加されたデータ
 * @details This function appends data read from a file to a buffer.
 * It returns the data that has been appended to the buffer.
 * The function returns NULL if an error occurs.
 */
char	*add_reads(char *buffer, int fd)
{
	char	*new_buffer;
	int		new_len;
	char	*aux;

	// 追加でBUFFER_SIZEバイト読み込む
	aux = new_read(fd);
	// ft_new_readが失敗した場合
	if (!aux)
		return (NULL);
	// ft_new_readが空文字列を返した場合
	if (!aux[0])
	{
		free(aux);
		return (buffer);
	}
	// bufferがNULLの場合(つまり、初回の読み込み)はauxをそのまま返す
	if (!buffer)
		return (aux);
	// bufferとauxの長さを足した新しい長さを取得
	new_len = ft_strlen(buffer) + ft_strlen(aux);
	// 新しい長さのメモリを確保(古いメモリは後でfreeする)
	new_buffer = malloc(new_len + 1);
	// mallocが失敗した場合
	if (!new_buffer)
		return (NULL);
	// bufferとauxを結合してnew_bufferにコピー
	ft_strlcpy(new_buffer, buffer, new_len + 1);
	ft_strlcat(new_buffer, aux, new_len + 1);
	// bufferとauxをfree
	free(buffer);
	free(aux);
	return (new_buffer);
}

/**
 * @fn new_read
 * @brief ファイルディスクリプタからBUFFER_SIZEバイト読み込む関数
 * @param fd ファイルディスクリプタ
 * @return BUFFER_SIZEバイトの文字列
 * @details This function reads BUFFER_SIZE bytes from a file descriptor.

	* It returns a string of BUFFER_SIZE bytes that has been read from the file descriptor.
 * The function returns NULL if an error occurs.
 */
char	*new_read(int fd)
{
	char	*aux;
	int		nbytes;

	// BUFFER_SIZEバイトのメモリを確保する
	aux = malloc(BUFFER_SIZE + 1);
	// mallocが失敗した場合
	if (!aux)
		return (NULL);
	// (追加で)BUFFER_SIZEバイト読み込む
	nbytes = read(fd, aux, BUFFER_SIZE);
	// readが失敗した場合
	if (nbytes < 0)
	{
		free(aux);
		return (NULL);
	}
	// 最後にNULL文字を追加する
	aux[nbytes] = '\0';
	return (aux);
}

/**
 * @fn ft_strchr
 * @brief 文字列s内の文字cを探す関数
 * @param s 文字列
 * @param c 探す文字
 * @return 文字cが見つかった位置へのポインタ

	* @details This function locates the first occurrence of c (converted to a char) in the string pointed to by s.

	* The terminating null character is considered to be part of the string; therefore if c is `\0`,
	the function locates the terminating `\0`.
 * The function returns a pointer to the located character,
	or a null pointer if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
