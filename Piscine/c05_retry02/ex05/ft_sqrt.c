/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:46:26 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/14 13:53:11 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= (nb / i))
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("36         : %d\n", ft_sqrt(36));
// 	printf("37         : %d\n", ft_sqrt(37));
// 	printf("38         : %d\n", ft_sqrt(38));
// 	printf("39         : %d\n", ft_sqrt(39));
// 	printf("40         : %d\n", ft_sqrt(40));
// 	printf("41         : %d\n", ft_sqrt(41));
// 	printf("42         : %d\n", ft_sqrt(42));
// 	printf("43         : %d\n", ft_sqrt(43));
// 	printf("44         : %d\n", ft_sqrt(44));
// 	printf("45         : %d\n", ft_sqrt(45));
// 	printf("46         : %d\n", ft_sqrt(46));
// 	printf("47         : %d\n", ft_sqrt(47));
// 	printf("48         : %d\n", ft_sqrt(48));
// 	printf("49         : %d\n", ft_sqrt(49));
// 	printf("2147483647 : %d\n", ft_sqrt(2147483647));
// }
