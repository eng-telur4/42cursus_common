/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:46:56 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 03:17:25 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	do_procedure_c(va_list ap)
{
	return (ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO));
}

int	do_procedure_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	return (ft_putstr_fd(s, STDOUT_FILENO));
}

int	do_procedure_p(va_list ap)
{
	void	*p;
	char	tmp_c[17];

	p = va_arg(ap, void *);
	if (!p)
		return (ft_putstr_fd("(nil)", STDOUT_FILENO));
	ft_itoa_ull((unsigned long long)p, tmp_c, "0123456789abcdef", 16);
	return (ft_putstr_fd("0x", STDOUT_FILENO) + ft_putstr_fd(tmp_c,
			STDOUT_FILENO));
}

int	do_procedure_di(va_list ap)
{
	return (ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO));
}

int	do_procedure_u(va_list ap)
{
	return (ft_putnbr_fd_u(va_arg(ap, unsigned int), STDOUT_FILENO));
}
