/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_strtol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:39:59 by skamijo           #+#    #+#             */
/*   Updated: 2024/11/10 03:03:11 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft.h"

static int	ft_isxdigit(int c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c
			&& c <= 'f'));
}

static int	get_base(const char **nptr, int *sign)
{
	int	base;

	base = 10;
	if (**nptr == '-')
	{
		*sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	if (base == 0 && **nptr == '0')
	{
		base = 8;
		(*nptr)++;
		if (ft_toupper(**nptr) == 'X' && ft_isxdigit((*nptr)[1]))
		{
			(*nptr)++;
			base = 16;
		}
	}
	else if (base == 16 && **nptr == '0' && ft_toupper((*nptr)[1]) == 'X')
		(*nptr) += 2;
	return (base);
}

static unsigned long	process_digits(const char **nptr, int base, int sign)
{
	unsigned long	result;
	unsigned long	value;

	result = 0;
	while (ft_isxdigit(**nptr))
	{
		if (ft_isdigit(**nptr))
			value = **nptr - '0';
		else
			value = ft_toupper(**nptr) - 'A' + 10;
		if (value >= (unsigned long)base)
			break ;
		if (sign == 1 && result > (LONG_MAX - value) / base)
			return (LONG_MAX);
		else if (sign == -1 && result > ((unsigned long)LONG_MAX + 1 - value)
			/ base)
			return (LONG_MIN);
		result = result * base + value;
		(*nptr)++;
	}
	return (result);
}

static long	ft_strtol(const char *nptr, char **endp, int base)
{
	unsigned long	result;
	char			*ep;
	int				sign;

	ep = (char *)nptr + ft_strlen((char *)nptr);
	sign = 1;
	if (base != 0 && !(base >= 2 && base <= 36))
		return (0);
	base = get_base(&nptr, &sign);
	result = process_digits(&nptr, base, sign);
	if (endp)
		*endp = (char *)nptr;
	if (ep != nptr)
		return (LONG_MAX);
	return (sign * result);
}

int	ft_atoi(const char *nptr)
{
	return ((int)ft_strtol(nptr, NULL, 10));
}
