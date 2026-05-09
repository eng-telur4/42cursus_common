/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:48:30 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/21 17:20:59 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
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
// 	ft_sort_int_tab(arr, arr_len);
// 	i = 0;
// 	while (i < arr_len)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }
