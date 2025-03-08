/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:34:05 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 01:45:20 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

int		ft_printf(const char *str, ...);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
t_bool	is_percent(char c);
void	ft_itoa_ull(unsigned long long val, char *a, char *base,
			unsigned long long radix);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_fd_u(unsigned int n, int fd);
int		ft_putnbr_fd_base(unsigned int n, char *base, int base_num, int fd);

int		do_procedure_c(va_list ap);
int		do_procedure_s(va_list ap);
int		do_procedure_p(va_list ap);
int		do_procedure_di(va_list ap);
int		do_procedure_u(va_list ap);
int		do_procedure_x(va_list ap);
int		do_procedure_upperx(va_list ap);
int		do_procedure_percent(void);
int		do_procedure_other(char c);
size_t	ft_strlen(const char *s);
int		validate_return_value(int ret, int len);
int		ft_numlen_base(long num, int base);

#endif // FT_PRINTF_H
