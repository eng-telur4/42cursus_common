/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:52:14 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:49:07 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	else if (dest_len < size)
	{
		while (src[i] != '\0' && dest_len < size - 1)
			dest[dest_len++] = src[i++];
		dest[dest_len] = '\0';
		return (dest_len + (src_len - i));
	}
	else
		return (src_len + size);
}

int	main(void)
{
	char new1[20] = "ABCDE";
	char new2[20] = "ABCDE";
	char new3[20] = "ABCDE";
	char old[] = "1234";
	// sizeがdestの長さ以下のとき：destのみ / srcの長さ+size
	printf("%d\n", ft_strlcat(new1, old, 2));
	printf("%s\n", new1);
	// sizeがdest+srcの長さ以下のとき：destの後ろにsrcが(size-destの長さ-1)結合される / dest+srcの長さ
	printf("%d\n", ft_strlcat(new2, old, 7));
	printf("%s\n", new2);
	// sizeがdest+srcの長さより大きいとき：destの後ろにsrcが全て結合される / dest+srcの長さ
	printf("%d\n", ft_strlcat(new3, old, 13));
	printf("%s\n", new3);
}