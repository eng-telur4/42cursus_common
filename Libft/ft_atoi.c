/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:56:25 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/29 14:20:32 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	unsigned long long	ret;
	int					sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && '0' <= *nptr && *nptr <= '9')
		ret = ret * 10 + (*nptr++ - '0');
	if (ret > LONG_MAX && sign == 1)
		return ((int)LONG_MAX);
	if (ret > (unsigned long long)LONG_MAX + 1 && sign == -1)
		return ((int)LONG_MIN);
	return ((int)(ret * sign));
}
