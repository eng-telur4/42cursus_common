/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:56:14 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:48:49 by skamijo          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int		dest_len;
	char	*tmp;

	tmp = dest;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}

int	main(void)
{
	char	str1[30] = "ABC";
	char	str2[] = "123";
	char	*p1;
	char	str3[30] = "ABC";
	char	str4[] = "123";
	char	*p2;
	char	*ret_val1;
	char	*ret_val2;
	char	*ret_val3;
	char	*ret_val4;
	char	*ret_val5;
	char	*ret_val6;

	p1 = "abcd";
	p2 = "abcd";
	/* 文字型配列に文字型配列を連結 */
	ret_val1 = strcat(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", ret_val1); // 返却値は連結後の文字列(=s1)
	ret_val2 = ft_strcat(str3, str4);
	printf("%s\n", str3);
	printf("%s\n", ret_val2);
	/* 文字型配列にポインタの指す文字列リテラルを連結 */
	ret_val3 = strcat(str1, p1);
	printf("%s\n", str1);
	printf("%s\n", ret_val3);
	ret_val4 = ft_strcat(str3, p2);
	printf("%s\n", str3);
	printf("%s\n", ret_val4);
	/* 文字型配列に文字列リテラルを連結 */
	ret_val5 = strcat(str1, "xyz");
	printf("%s\n", str1);
	printf("%s\n", ret_val5);
	ret_val6 = ft_strcat(str3, "xyz");
	printf("%s\n", str3);
	printf("%s\n", ret_val6);
}
