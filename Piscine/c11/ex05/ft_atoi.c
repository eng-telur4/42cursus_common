/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:12:12 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/11 20:40:01 by skamijo          ###   ########.fr       */
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

int	overflowl(int sign, int l, char next)
{
	if (sign == 1)
	{
		if (INT_MAX / 10 < l)
			return (1);
		if (INT_MAX / 10 == l && INT_MAX % 10 <= next - '0')
			return (1);
	}
	if (sign == -1)
	{
		if (INT_MIN / -10 < l)
			return (-1);
		if (INT_MIN / -10 == l && INT_MIN % -10 * -1 <= next - '0')
			return (-1);
	}
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
			sign = -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			if (overflowl(sign, ret, *str) == 1)
				return (INT_MAX);
			if (overflowl(sign, ret, *str) == -1)
				return (INT_MIN);
			ret = ret * 10 + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (ret * sign);
}
