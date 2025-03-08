/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:41:33 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 03:13:09 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_u(unsigned int n, int fd)
{
	int	ret;

	ret = 0;
	if (n > 9)
	{
		ret += ft_putnbr_fd_u(n / 10, fd);
		ret += ft_putnbr_fd_u(n % 10, fd);
	}
	else
		ret += ft_putchar_fd(n + 48, fd);
	return (ret);
}
