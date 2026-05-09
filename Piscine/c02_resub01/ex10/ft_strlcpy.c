/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:41:35 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/08 13:09:47 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char			str[6];
// 	unsigned int	str_cnt;

// 	str_cnt = ft_strlcpy(str, "hello", 10);
// 	printf("%s\n", str);
// 	printf("%d\n", str_cnt);
// 	printf("%d\n", str[str_cnt] == '\0');
// 	str_cnt = ft_strlcpy(str, "hello", 4);
// 	printf("%s\n", str);
// 	printf("%d\n", str_cnt);
// 	printf("%d\n", str[str_cnt] == '\0');
// }
