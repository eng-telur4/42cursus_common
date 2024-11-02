/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:38:00 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/29 13:33:56 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	num;

	len = ft_num_len(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	while (len-- > 0)
	{
		if (str[len] != '-')
			str[len] = '0' + (num % 10);
		num /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
