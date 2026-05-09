/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:38:21 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/05 19:12:15 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 10;
// 	b = 3;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("div a : %d, mod b : %d\n", a, b);
// }
