/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 02:40:56 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/19 10:54:28 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	num_comb(int n, int r)
{
	int	result;
	int	i;

	if (r > n - r)
		r = n - r;
	result = 1;
	i = 0;
	while (i < r)
	{
		result = result * (n - i) / (i + 1);
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_comb(int i, int j, int k)
{
	ft_putchar(i + '0');
	ft_putchar(j + '0');
	ft_putchar(k + '0');
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;
	int	count;

	count = 0;
	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				print_comb(i, j, k);
				if (num_comb(10, 3) != ++count)
					ft_putstr(", ");
				k++;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb();
// }
