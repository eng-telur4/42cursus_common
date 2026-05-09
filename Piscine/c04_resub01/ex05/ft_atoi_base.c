/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:48:30 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 12:34:31 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_index(char *base, char value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (base[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	atoi_base(char *str, char *base, int len)
{
	int	ret;
	int	sign;
	int	i;

	i = 0;
	ret = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (get_index(base, str[i], len) != -1)
		{
			ret = ret * len + get_index(base, str[i], len);
			i++;
		}
		else
			break ;
	}
	return (ret * sign);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	len;

	len = 0;
	while (base[len])
		len += 1;
	result = check_base(base);
	if (result)
		return (atoi_base(str, base, len));
	return (0);
}

// int	main(void)
// {
// 	char decimal_base[] = "0123456789";
// 	char binary_base[] = "01";
// 	char hexadecimal_base[] = "0123456789ABCDEF";
// 	char octal_base[] = "poneyvif";

// 	printf("%d\n", get_index(decimal_base, '1', 10));
// 	printf("%d\n", get_index(decimal_base, '0', 10));
// 	printf("%d\n", ft_atoi_base("10", decimal_base));
// 	printf("%d\n", ft_atoi_base("101", binary_base));
// 	printf("%d\n", ft_atoi_base("36", hexadecimal_base));
// 	printf("%d\n", ft_atoi_base("yf", octal_base));
// 	printf("%d\n", ft_atoi_base("2147483647", decimal_base));
// 	printf("%d\n", ft_atoi_base("-2147483648", decimal_base));
// 	printf("%d\n", ft_atoi_base("  ---+--+1234ab567", decimal_base));
// }