/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:02 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/08 23:30:05 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(const char *str, va_list ap)
{
	if (*str == 'c')
		return (do_procedure_c(ap));
	else if (*str == 's')
		return (do_procedure_s(ap));
	else if (*str == 'p')
		return (do_procedure_p(ap));
	else if (*str == 'd' || *str == 'i')
		return (do_procedure_di(ap));
	else if (*str == 'u')
		return (do_procedure_u(ap));
	else if (*str == 'x')
		return (do_procedure_x(ap));
	else if (*str == 'X')
		return (do_procedure_upperx(ap));
	else if (*str == '%')
		return (do_procedure_percent());
	else
		return (do_procedure_other(*str));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ret += handle_percent(str, ap);
		}
		else
			ret += ft_putchar_fd(*str, STDOUT_FILENO);
		str++;
	}
	va_end(ap);
	return (ret);
}
