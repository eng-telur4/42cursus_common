/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:57:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/05 14:38:07 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 1;
// 	b = 5;
// 	printf("a : %d, b : %d\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("a : %d, b : %d\n", a, b);
// }
