/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:53:33 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/19 10:50:39 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	d;
	int	dc;

	d = 0;
	while (d <= 9)
	{
		dc = d + '0';
		write(1, &dc, 1);
		d++;
	}
}

// int	main(void)
// {
// 	ft_print_numbers();
// 	return (0);
// }
