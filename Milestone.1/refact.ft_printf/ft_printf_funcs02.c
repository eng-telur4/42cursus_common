/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:46:59 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/17 19:08:51 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_procedure_x(va_list ap)
{
	return (ft_putnbr_fd_base((unsigned int)va_arg(ap, unsigned int),
			"0123456789abcdef", 16, STDOUT_FILENO));
}

int	do_procedure_upperx(va_list ap)
{
	return (ft_putnbr_fd_base((unsigned int)va_arg(ap, unsigned int),
			"0123456789ABCDEF", 16, STDOUT_FILENO));
}

int	do_procedure_percent(void)
{
	return (ft_putchar_fd('%', STDOUT_FILENO));
}

int	do_procedure_other(char c)
{
	return (ft_putchar_fd('%', STDOUT_FILENO) + ft_putchar_fd(c,
			STDOUT_FILENO));
}
