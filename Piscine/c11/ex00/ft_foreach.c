/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:07:39 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 18:38:30 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

void	ft_putnum(int num)
{
	char	c;

	c = '0' + num;
	write(1, &c, 1);
}

// int	main(void)
// {
// 	int	arr[5];

// 	arr[0] = 1;
// 	arr[1] = 2;
// 	arr[2] = 3;
// 	arr[3] = 4;
// 	arr[4] = 5;
// 	ft_foreach(arr, 5, &ft_putnum);
// }
