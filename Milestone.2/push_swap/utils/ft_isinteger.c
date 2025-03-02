/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:43:19 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/01 06:26:50 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <limits.h>

bool	ft_isinteger(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!str || !*str)
		return (false);
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		if (num > (INT_MAX / 10) || (num == (INT_MAX / 10) && ((sign == 1
						&& *str - '0' > 7) || (sign == -1 && *str - '0' > 8))))
			return (false);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (true);
}
