/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:25:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 18:38:55 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			count++;
		i++;
	}
	if (count == length - 1)
		return (1);
	i = 0;
	count = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			count++;
		i++;
	}
	if (count == length - 1)
		return (1);
	return (0);
}

int	ft_intcmp(int n1, int n2)
{
	return (n1 - n2);
}

// int	main(void)
// {
// 	int	arr1[] = {1, 2, 3, 4, 5};
// 	int	arr2[] = {5, 4, 3, 2, 1};
// 	int	arr3[] = {1, 2, 3, 5, 4};
// 	int	arr4[] = {1, 2, 3, 4, 2};
// 	int	arr5[] = {5, 4, 3, 2, 5};

// 	printf("%d\n", ft_is_sort(arr1, 5, ft_intcmp));
// 	printf("%d\n", ft_is_sort(arr2, 5, ft_intcmp));
// 	printf("%d\n", ft_is_sort(arr3, 5, ft_intcmp));
// 	printf("%d\n", ft_is_sort(arr4, 5, ft_intcmp));
// 	printf("%d\n", ft_is_sort(arr5, 5, ft_intcmp));
// }
