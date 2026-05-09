/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:13 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:48:55 by skamijo          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;
	char			*tmp;

	tmp = dest;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	i = 0;
	while (*src != '\0' && i < nb)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (tmp);
}

int	main(void)
{
	char	str1[20] = "ABC";
	char	str2[] = "12345";
	char	str3[20] = "ABC";
	char	str4[] = "12345";
	char	*ret_val1;
	char	*ret_val2;
	char	*ret_val3;
	char	*ret_val4;

	/* str2の長さ >= n */
	ret_val1 = strncat(str1, str2, 3);
	printf("%s\n", str1);
	printf("%s\n", ret_val1); // 返却値は連結後の文字列(=s1)
	/* str4の長さ >= n */
	ret_val2 = ft_strncat(str3, str4, 3);
	printf("%s\n", str3);
	printf("%s\n", ret_val2);
	/* str2の長さ < n */
	ret_val3 = strncat(str1, str2, 10);
	printf("%s\n", str1);
	printf("%s\n", ret_val3);
	/* str4の長さ < n */
	ret_val4 = ft_strncat(str3, str4, 10);
	printf("%s\n", str3);
	printf("%s\n", ret_val4);
	return (0);
}
