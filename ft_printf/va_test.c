#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	va_arg_test(char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (fmt != NULL)
	{
		printf("%s\n", fmt);
		fmt = va_arg(ap, char *);
	}
	va_end(ap);
}

void	sum_product(double *sum, double *product, int n, ...)
{
	va_list	ap;
	va_list	dest;
	int		i;

	// nからスタートさせているのがポイント
	va_start(ap, n);
	va_copy(dest, ap);
	*sum = 0.0;
	*product = 0.0;
	// 総和
	i = 0;
	while (i < n)
	{
		*sum += va_arg(ap, double);
		i++;
	}
	// 総乗
	*product = va_arg(dest, double);
	i = 1;
	while (i < n)
	{
		*product *= va_arg(dest, double);
		i++;
	}
	va_end(ap);
	va_end(dest);
}

int	main(void)
{
	double	sum;
	double	product;

	va_arg_test("aiueo", "test", "aaaaaa", NULL);
	sum_product(&sum, &product, 4, 1.0, 2.0, 3.0, 4.0);
	printf("総和 : %.1f\n", sum);
	printf("総乗 : %.1f\n", product);
	ft_putstr_fd("==========\n", STDOUT_FILENO);
}
