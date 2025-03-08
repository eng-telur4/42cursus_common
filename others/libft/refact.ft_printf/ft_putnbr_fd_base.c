/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:42:01 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/13 01:20:05 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_base(unsigned int n, char *base, int base_num, int fd)
{
	int	ret;

	ret = 0;
	if (n >= (unsigned int)base_num)
	{
		ret += ft_putnbr_fd_base(n / base_num, base, base_num, fd);
		ret += ft_putnbr_fd_base(n % base_num, base, base_num, fd);
	}
	else
		ret += ft_putchar_fd(base[n], fd);
	return (ret);
}
