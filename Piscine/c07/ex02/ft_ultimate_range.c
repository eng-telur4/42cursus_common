/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:59:49 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/15 19:42:12 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = malloc(sizeof(int) * (max - min));
	if (result == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = result;
	i = 0;
	while (max > min)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*tab;
// 	int	size;
// 	int	i;

// 	i = 0;
// 	min = -10;
// 	max = 25;
// 	size = ft_ultimate_range(&tab, min, max);
// 	while (i < size)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// }
