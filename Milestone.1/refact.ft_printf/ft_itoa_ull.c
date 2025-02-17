/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:40:44 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/17 19:54:06 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_ull(unsigned long long val, char *a, char *base,
		unsigned long long radix)
{
	char				*p;
	unsigned long long	v;
	unsigned long long	n;

	p = a;
	v = val;
	n = 1;
	while (v >= radix)
	{
		v /= radix;
		n++;
	}
	p = a + n;
	v = val;
	*p = '\0';
	--p;
	*p = base[v % radix];
	v /= radix;
	while (p != a)
	{
		--p;
		*p = base[v % radix];
		v /= radix;
	}
}
