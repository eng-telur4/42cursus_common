/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:09:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/07 11:52:16 by skamijo          ###   ########.fr       */
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

int	ft_str_is_alpha(char *str)
{
	int	i;

	if (ft_strlen(str))
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (!(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i]
						&& str[i] <= 'Z')))
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
// 	printf("%d\n", ft_str_is_alpha("hello"));
// 	printf("%d\n", ft_str_is_alpha("he11o"));
// }
