/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 02:40:56 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/19 13:36:39 by skamijo          ###   ########.fr       */
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

void	print_combination(int *pattern, int count, int r)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < pattern[i])
		{
			ft_putchar(i + '0');
			j++;
		}
		i++;
	}
	if (num_comb(10, r) != count)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	combination(int *pattern, int r, int num_decided)
{
	static int	count = 0;
	int			num_selected;
	int			i;

	num_selected = 0;
	i = 0;
	while (i < num_decided)
	{
		num_selected += pattern[i];
		i++;
	}
	if (num_decided == 10)
	{
		if (num_selected == r)
			print_combination(pattern, ++count, r);
		return ;
	}
	else
	{
		pattern[num_decided] = 1;
		combination(pattern, r, num_decided + 1);
		pattern[num_decided] = 0;
		combination(pattern, r, num_decided + 1);
	}
}

void	ft_print_combn(int n)
{
	int	pattern[10];

	combination(pattern, n, 0);
}

int	main(void)
{
	ft_print_combn(5);
}
