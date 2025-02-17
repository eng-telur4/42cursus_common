/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:02 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/17 19:50:14 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(const char *str, va_list ap)
{
	t_procedures	procedures[] = {{'c', do_procedure_c}, {'s',
			do_procedure_s}, {'p', do_procedure_p}, {'d', do_procedure_di},
			{'i', do_procedure_di}, {'u', do_procedure_u}, {'x',
			do_procedure_x}, {'X', do_procedure_upperx}, {-1, NULL}};
	int				i;

	i = 0;
	while (procedures[i].identify != -1)
	{
		if (*str == procedures[i].identify)
			return (procedures[i].do_procedure(ap));
		i++;
	}
	if (*str == '%')
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
