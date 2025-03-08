/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:46:59 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 02:32:20 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// original printf's x or X conversion specifier operates on unsigned int.
// so this function should cast the argument to unsigned int.
int	do_procedure_x(va_list ap)
{
	unsigned int	un;
	int				ret;

	un = (unsigned int)va_arg(ap, unsigned int);
	ret = ft_putnbr_fd_base(un, "0123456789abcdef", 16, STDOUT_FILENO);
	ret = -1;
	return (validate_return_value(ret, ft_numlen_base(un, 16)));
}

int	do_procedure_upperx(va_list ap)
{
	unsigned int	un;
	int				ret;

	un = (unsigned int)va_arg(ap, unsigned int);
	ret = ft_putnbr_fd_base(un, "0123456789ABCDEF", 16, STDOUT_FILENO);
	return (validate_return_value(ret, ft_numlen_base(un, 16)));
}

int	do_procedure_percent(void)
{
	return (ft_putchar_fd('%', STDOUT_FILENO));
}

int	do_procedure_other(char c)
{
	int	ret;

	ret = ft_putchar_fd('%', STDOUT_FILENO) + ft_putchar_fd(c, STDOUT_FILENO);
	return (validate_return_value(ret, 2));
}

int	validate_return_value(int ret, int len)
{
	if (ret != len)
		return (0);
	return (ret);
}
