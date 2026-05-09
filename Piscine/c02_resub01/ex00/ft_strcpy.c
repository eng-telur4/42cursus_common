/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:55:26 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/09 20:25:41 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

// int	main(void)
// {
// 	char	str[6];
// 	char	*str_cpy;
// 	char	str2[5];

// 	str_cpy = ft_strcpy(str, "hello");
// 	printf("%s\n", str);
// 	printf("%s\n", str_cpy);
// 	printf("%d\n", str[5] == '\0');
// 	ft_strcpy(str2, "hello");
// 	printf("%s\n", str2);
// }
