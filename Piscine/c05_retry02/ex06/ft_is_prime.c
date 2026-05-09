/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:37:10 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/14 13:53:16 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	printf("2          : %d\n", ft_is_prime(2));
// 	printf("3          : %d\n", ft_is_prime(3));
// 	printf("4          : %d\n", ft_is_prime(4));
// 	printf("5          : %d\n", ft_is_prime(5));
// 	printf("6          : %d\n", ft_is_prime(6));
// 	printf("7          : %d\n", ft_is_prime(7));
// 	printf("8          : %d\n", ft_is_prime(8));
// 	printf("9          : %d\n", ft_is_prime(9));
// 	printf("2147483647 : %d\n", ft_is_prime(2147483647));
// }
