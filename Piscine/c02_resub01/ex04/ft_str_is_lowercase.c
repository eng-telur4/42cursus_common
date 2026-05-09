/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:09:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/07 11:52:46 by skamijo          ###   ########.fr       */
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

int	ft_str_is_lowercase(char *str)
{
	int	i;

	if (ft_strlen(str))
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (!('a' <= str[i] && str[i] <= 'z'))
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
// 	printf("%d\n", ft_str_is_lowercase("hello"));
// 	printf("%d\n", ft_str_is_lowercase("he11o"));
// 	printf("%d\n", ft_str_is_lowercase("hEllo"));
// }
