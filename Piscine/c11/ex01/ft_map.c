/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:20:14 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 18:38:39 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	arr = (int *)malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}

int	to_double(int n)
{
	return (n * 2);
}

// int	main(void)
// {
// 	int	arr[5];
// 	int	*ret_arr;
// 	int	i;

// 	arr[0] = 1;
// 	arr[1] = 2;
// 	arr[2] = 3;
// 	arr[3] = 4;
// 	arr[4] = 5;
// 	ret_arr = ft_map(arr, 5, &to_double);
// 	i = 0;
// 	while (i < 5)
// 		printf("%d\n", ret_arr[i++]);
// }
