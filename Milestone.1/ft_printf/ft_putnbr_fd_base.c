/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:42:01 by skamijo           #+#    #+#             */
/*   Updated: 2024/11/10 03:19:28 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_fd_base(long long n, char *base, int base_num, int fd)
{
	int	ret;

	ret = 0;
	if (n >= base_num)
	{
		ret += ft_putnbr_fd_base(n / base_num, base, base_num, fd);
		ret += ft_putnbr_fd_base(n % base_num, base, base_num, fd);
	}
	else
		ret += ft_putchar_fd(base[n], fd);
	return (ret);
}
