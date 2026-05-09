/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:09:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/07 13:54:09 by skamijo          ###   ########.fr       */
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

int	ft_str_is_printable(char *str)
{
	int	i;

	if (ft_strlen(str))
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (!(32 <= str[i] && str[i] <= 126))
			{
				return (0);
			}
			i++;
		}
	}
	return (1);
}

// int	main(void)
// {
// 	char	str1[6] = "hell";
// 	char	str2[6];
// 	char	str3[6];

// 	str1[5] = (char)40;
// 	str2[0] = (char)32;
// 	str3[0] = (char)127;
// 	printf("%d\n", ft_str_is_printable(str1));
// 	printf("%d\n", ft_str_is_printable(str2));
// 	printf("%d\n", ft_str_is_printable(str3));
// }
