/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:46 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/15 19:42:06 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ret_val;

	if (min >= max)
		return (NULL);
	ret_val = (int *)malloc((max - min) * sizeof(int));
	i = min;
	while (i < max)
	{
		ret_val[i - min] = i;
		i++;
	}
	return (ret_val);
}

// int	main(void)
// {
// 	int	*ret_val;
// 	int	i;

// 	ret_val = ft_range(-10, 25);
// 	i = 0;
// 	while (i < 35)
// 		printf("%d ", ret_val[i++]);
// }
