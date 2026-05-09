/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:08:49 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/14 13:52:34 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

// int	main(void)
// {
// 	printf("(-1)! : %d\n", ft_recursive_factorial(-1));
// 	printf("   0! : %d\n", ft_recursive_factorial(0));
// 	printf("   1! : %d\n", ft_recursive_factorial(1));
// 	printf("   2! : %d\n", ft_recursive_factorial(2));
// 	printf("   3! : %d\n", ft_recursive_factorial(3));
// 	printf("   4! : %d\n", ft_recursive_factorial(4));
// 	printf("   5! : %d\n", ft_recursive_factorial(5));
// 	printf("   6! : %d\n", ft_recursive_factorial(6));
// 	printf("   7! : %d\n", ft_recursive_factorial(7));
// 	printf("   8! : %d\n", ft_recursive_factorial(8));
// 	printf("   9! : %d\n", ft_recursive_factorial(9));
// 	printf("  10! : %d\n", ft_recursive_factorial(10));
// }
