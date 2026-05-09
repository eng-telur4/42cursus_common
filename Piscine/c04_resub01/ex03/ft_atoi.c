/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:12:12 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 12:33:30 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			ret = ret * 10 + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (ret * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi("  ---+--+1234ab567"));
	printf("%d\n", ft_atoi("  ---+--+2147483648ab567"));
	printf("%d\n", ft_atoi("  --+--+2147483647ab567"));
}
