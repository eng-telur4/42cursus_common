/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:40:04 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/23 03:23:39 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	b[2];

	i = 0;
	while (str[i])
	{
		if (32 <= str[i] && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			b[0] = "0123456789abcdef"[(unsigned char)str[i] / 16];
			b[1] = "0123456789abcdef"[(unsigned char)str[i] % 16];
			write(1, "\\", 1);
			write(1, &b[0], 1);
			write(1, &b[1], 1);
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr_non_printable("Coucou\ntu vas bien ?");
// 	// ft_putstr_non_printable("Coucou\tu vas bien ?");
// 	// ft_putstr_non_printable("Coucou\rtu vas bien ?");
// }
