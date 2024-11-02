/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:02 by skamijo           #+#    #+#             */
/*   Updated: 2024/11/02 13:11:34 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libftprintf.h"

// int	ft_printf(const char *str, ...)
// {
// 	va_list	ap;
// 	char	tmp_c[17];
// 	int		ret;

// 	ret = 0;
// 	va_start(ap, str);
// 	while (*str)
// 	{
// 		if (is_percent(*str))
// 		{
// 			str++;
// 			if (*str == 'c')
// 				ret += ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
// 			else if (*str == 's')
// 				ret += ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
// 			else if (*str == 'p')
// 			{
// 				ft_itoa_ull((unsigned long long)va_arg(ap, void *), tmp_c,
// 					"0123456789abcdef", 16);
// 				ret += ft_putstr_fd("0x", STDOUT_FILENO);
// 				ret += ft_putstr_fd(tmp_c, STDOUT_FILENO);
// 			}
// 			else if (*str == 'd' || *str == 'i')
// 				ret += ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO);
// 			else if (*str == 'u')
// 				ret += ft_putnbr_fd_u(va_arg(ap, unsigned int), STDOUT_FILENO);
// 			else if (*str == 'x')
// 				ret += ft_putnbr_fd_base(va_arg(ap, long long),
// 						"0123456789abcdef", 16, STDOUT_FILENO);
// 			else if (*str == 'X')
// 				ret += ft_putnbr_fd_base(va_arg(ap, long long),
// 						"0123456789ABCDEF", 16, STDOUT_FILENO);
// 			else if (*str == '%')
// 				ret += ft_putchar_fd('%', STDOUT_FILENO);
// 			else
// 			{
// 				ret += ft_putchar_fd('%', STDOUT_FILENO);
// 				ret += ft_putchar_fd(*str, STDOUT_FILENO);
// 			}
// 		}
// 		else
// 			ret += ft_putchar_fd(*str, STDOUT_FILENO);
// 		str++;
// 	}
// 	va_end(ap);
// 	return (ret);
// }

// void	va_arg_test(char *fmt, ...)
// {
// 	va_list	ap;

// 	va_start(ap, fmt);
// 	while (fmt != NULL)
// 	{
// 		printf("%s\n", fmt);
// 		fmt = va_arg(ap, char *);
// 	}
// 	va_end(ap);
// }

// void	sum_product(double *sum, double *product, int n, ...)
// {
// 	va_list	ap;
// 	va_list	dest;
// 	int		i;

// 	// nからスタートさせているのがポイント
// 	va_start(ap, n);
// 	va_copy(dest, ap);
// 	*sum = 0.0;
// 	*product = 0.0;
// 	// 総和
// 	i = 0;
// 	while (i < n)
// 	{
// 		*sum += va_arg(ap, double);
// 		i++;
// 	}
// 	// 総乗
// 	*product = va_arg(dest, double);
// 	i = 1;
// 	while (i < n)
// 	{
// 		*product *= va_arg(dest, double);
// 		i++;
// 	}
// 	va_end(ap);
// 	va_end(dest);
// }

// int	main(void)
// {
// 	double	sum;
// 	double	product;
// 	int		ret01;
// 	int		ret02;

// 	va_arg_test("aiueo", "test", "aaaaaa", NULL);
// 	sum_product(&sum, &product, 4, 1.0, 2.0, 3.0, 4.0);
// 	printf("総和 : %.1f\n", sum);
// 	printf("総乗 : %.1f\n", product);
// 	ft_putstr_fd("==========\n", STDOUT_FILENO);
// 	ret01 = ft_printf("12[%c]8[%%][%s]e%wr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X]\n",
// 			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff);
// 	ret02 = printf("12[%c]8[%%][%s]e%wr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X]\n",
// 			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff);
// 	printf("length : %d\n", ret01);
// 	printf("length : %d\n", ret02);
// 	return (EXIT_SUCCESS);
// }
