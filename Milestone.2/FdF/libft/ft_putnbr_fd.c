/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:42:06 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 03:11:23 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ret += ft_putchar_fd('-', fd);
		ret += ft_putchar_fd('2', fd);
		ret += ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ret += ft_putchar_fd('-', fd);
		ret += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ret += ft_putnbr_fd(n / 10, fd);
		ret += ft_putnbr_fd(n % 10, fd);
	}
	else
		ret += ft_putchar_fd(n + '0', fd);
	return (ret);
}
