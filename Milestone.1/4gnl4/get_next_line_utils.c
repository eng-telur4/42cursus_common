/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:40:12 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/06 21:05:56 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @fn ft_strlen
 * @brief 文字列の長さを取得する関数
 * @param s 文字列
 * @return 文字列の長さ
 * @details This function returns the length of a string.
 * It returns 0 if the string is NULL.
 */
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

/**
 * @fn ft_strdup
 * @brief 文字列を複製する関数
 * @param s 文字列
 * @return 複製された文字列のポインタ
 * @details This function duplicates a string.
 * It returns a pointer to the duplicated string.
 * The function returns NULL if an error occurs.
 */
char	*ft_strdup(const char *s)
{
	int		len;
	char	*d;
	int		i;

	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/**
 * @fn ft_substr
 * @brief 文字列の一部を取得する関数
 * @param s 文字列
 * @param start 開始位置
 * @param len 長さ
 * @return 部分文字列
 * @details This function returns a substring of a string.
 * It returns a substring starting from the index start of the string s,
 * with a length of len characters.
 * The function returns NULL if an error occurs.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/**
 * @fn ft_strlcpy
 * @brief 文字列をコピーする関数 (strncpyのラッパー)
 * @param dst 目的地の文字列
 * @param src 元の文字列
 * @param size コピーする最大の長さ
 * @return コピーされた文字列の長さ
 * @details This function copies a string (strncpy wrapper).
 * It copies up to size - 1 characters from the string src to dst,
 * NUL-terminating the result if size is not 0.
 * The function returns the length of the string it tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}

/**
 * @fn ft_strlcat
 * @brief 文字列を連結する関数 (strncatのラッパー)
 * @param dst 目的地の文字列
 * @param src 元の文字列
 * @param size 追加する最大の長さ
 * @return 連結後の文字列の長さ
 * @details This function concatenates a string (strncat wrapper).
 * It concatenates up to size
	- 1 characters from the string src to the end of the string dst,
 * NUL-terminating the result if size is not 0.
 * The function returns the length of the string it tried to create.
 * If the return value is equal to or more than size,
	the output string would not be NUL-terminated.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
