/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:09:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/07 11:52:36 by skamijo          ###   ########.fr       */
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

int	ft_str_is_numeric(char *str)
{
	int	i;

	if (ft_strlen(str))
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (!('0' <= str[i] && str[i] <= '9'))
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
// 	printf("%d\n", ft_str_is_numeric("12345"));
// 	printf("%d\n", ft_str_is_numeric("5432l"));
// }
