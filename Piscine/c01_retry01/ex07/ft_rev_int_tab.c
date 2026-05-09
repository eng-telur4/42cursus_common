/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:40:09 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:14:54 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

// int	main(void)
// {
// 	int	arr[5];
// 	int	arr_len;
// 	int	i;

// 	arr[0] = 3;
// 	arr[1] = 5;
// 	arr[2] = 2;
// 	arr[3] = 1;
// 	arr[4] = 4;
// 	arr_len = sizeof(arr) / sizeof(int);
// 	i = 0;
// 	while (i < arr_len)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_rev_int_tab(arr, arr_len);
// 	i = 0;
// 	while (i < arr_len)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }
