/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 02:40:56 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/19 10:54:27 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			count++;
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			ft_putchar(' ');
			ft_putchar(j / 10 + '0');
			ft_putchar(j % 10 + '0');
			if (count != 4950)
				ft_putstr(", ");
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// }
