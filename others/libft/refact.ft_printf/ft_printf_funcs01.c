/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:46:56 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 02:34:16 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_procedure_c(va_list ap)
{
	int	ret;

	ret = ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
	return (validate_return_value(ret, 1));
}

int	do_procedure_s(va_list ap)
{
	char	*s;
	int		ret;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	ret = ft_putstr_fd(s, STDOUT_FILENO);
	return (validate_return_value(ret, ft_strlen(s)));
}

int	do_procedure_p(va_list ap)
{
	void	*p;
	char	tmp_c[17];
	int		ret;

	p = va_arg(ap, void *);
	if (!p)
	{
		ret = ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (validate_return_value(ret, 5));
	}
	ft_itoa_ull((unsigned long long)p, tmp_c, "0123456789abcdef", 16);
	ret = ft_putstr_fd("0x", STDOUT_FILENO) + ft_putstr_fd(tmp_c,
			STDOUT_FILENO);
	return (validate_return_value(ret, ft_strlen(tmp_c) + 2));
}

int	do_procedure_di(va_list ap)
{
	int	n;
	int	ret;

	n = va_arg(ap, int);
	ret = ft_putnbr_fd(n, STDOUT_FILENO);
	return (validate_return_value(ret, ft_numlen_base(n, 10)));
}

int	do_procedure_u(va_list ap)
{
	int	un;
	int	ret;

	un = va_arg(ap, unsigned int);
	ret = ft_putnbr_fd_u(un, STDOUT_FILENO);
	return (validate_return_value(ret, ft_numlen_base(un, 10)));
}
