#include "libftprintf.h"

int	main(void)
{
	int	ret01;
	int	ret02;

	ret01 = ft_printf("12[%c]8[%%][%s]ewr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X][%d]\n",
			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff,
			'A');
	ret02 = printf("12[%c]8[%%][%s]ewr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X][%d]\n",
			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff,
			'A');
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	return (EXIT_SUCCESS);
}
