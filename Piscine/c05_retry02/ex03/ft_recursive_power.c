/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:19:41 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/14 13:52:58 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

// int	main(void)
// {
// 	printf("0^ 0 : %d\n", ft_recursive_power(0, 0));
// 	printf("2^-1 : %d\n", ft_recursive_power(2, -1));
// 	printf("2^ 0 : %d\n", ft_recursive_power(2, 0));
// 	printf("2^ 1 : %d\n", ft_recursive_power(2, 1));
// 	printf("2^ 2 : %d\n", ft_recursive_power(2, 2));
// 	printf("2^ 3 : %d\n", ft_recursive_power(2, 3));
// 	printf("2^ 3 : %d\n", ft_recursive_power(2, 3));
// 	printf("2^ 4 : %d\n", ft_recursive_power(2, 4));
// 	printf("2^ 5 : %d\n", ft_recursive_power(2, 5));
// 	printf("2^ 6 : %d\n", ft_recursive_power(2, 6));
// 	printf("2^ 7 : %d\n", ft_recursive_power(2, 7));
// 	printf("2^ 8 : %d\n", ft_recursive_power(2, 8));
// 	printf("2^ 9 : %d\n", ft_recursive_power(2, 9));
// 	printf("2^10 : %d\n", ft_recursive_power(2, 10));
// }
