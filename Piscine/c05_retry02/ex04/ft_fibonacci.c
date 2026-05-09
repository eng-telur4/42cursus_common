/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:34:08 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/14 13:53:05 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int	main(void)
// {
// 	printf("term -1 : %d\n", ft_fibonacci(-1));
// 	printf("term  0 : %d\n", ft_fibonacci(0));
// 	printf("term  1 : %d\n", ft_fibonacci(1));
// 	printf("term  2 : %d\n", ft_fibonacci(2));
// 	printf("term  3 : %d\n", ft_fibonacci(3));
// 	printf("term  4 : %d\n", ft_fibonacci(4));
// 	printf("term  5 : %d\n", ft_fibonacci(5));
// 	printf("term  6 : %d\n", ft_fibonacci(6));
// 	printf("term  7 : %d\n", ft_fibonacci(7));
// 	printf("term  8 : %d\n", ft_fibonacci(8));
// 	printf("term  9 : %d\n", ft_fibonacci(9));
// 	printf("term 10 : %d\n", ft_fibonacci(10));
// 	printf("term 11 : %d\n", ft_fibonacci(11));
// 	printf("term 12 : %d\n", ft_fibonacci(12));
// 	printf("term 13 : %d\n", ft_fibonacci(13));
// 	printf("term 14 : %d\n", ft_fibonacci(14));
// 	printf("term 15 : %d\n", ft_fibonacci(15));
// }
