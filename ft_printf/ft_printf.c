/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:02 by skamijo           #+#    #+#             */
/*   Updated: 2024/11/10 03:19:24 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	tmp_c[17];
	int		ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (is_percent(*str))
		{
			str++;
			if (*str == 'c')
				ret += ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
			else if (*str == 's')
				ret += ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
			else if (*str == 'p')
			{
				ft_itoa_ull((unsigned long long)va_arg(ap, void *), tmp_c,
					"0123456789abcdef", 16);
				ret += ft_putstr_fd("0x", STDOUT_FILENO);
				ret += ft_putstr_fd(tmp_c, STDOUT_FILENO);
			}
			else if (*str == 'd' || *str == 'i')
				ret += ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO);
			else if (*str == 'u')
				ret += ft_putnbr_fd_u(va_arg(ap, unsigned int), STDOUT_FILENO);
			else if (*str == 'x')
				ret += ft_putnbr_fd_base(va_arg(ap, long long),
						"0123456789abcdef", 16, STDOUT_FILENO);
			else if (*str == 'X')
				ret += ft_putnbr_fd_base(va_arg(ap, long long),
						"0123456789ABCDEF", 16, STDOUT_FILENO);
			else if (*str == '%')
				ret += ft_putchar_fd('%', STDOUT_FILENO);
			else
			{
				ret += ft_putchar_fd('%', STDOUT_FILENO);
				ret += ft_putchar_fd(*str, STDOUT_FILENO);
			}
		}
		else
			ret += ft_putchar_fd(*str, STDOUT_FILENO);
		str++;
	}
	va_end(ap);
	return (ret);
}
