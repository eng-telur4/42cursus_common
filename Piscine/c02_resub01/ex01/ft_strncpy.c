/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:25:00 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/21 19:38:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = dest;
	while (i < n && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (tmp);
}

// int	main(void)
// {
// 	char	str[6];
// 	char	str1[6];
// 	char	*str_cpy;
// 	char	*str_cpy1;

// 	str_cpy = ft_strncpy(str, "hello", 10);
// 	printf("%s\n", str);
// 	printf("%s\n", str_cpy);
// 	str_cpy1 = ft_strncpy(str1, "hello", 4);
// 	printf("%s\n", str1);
// 	printf("%s\n", str_cpy1);
// }
