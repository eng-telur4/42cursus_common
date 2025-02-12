#include "../ft_printf/ft_printf.h"

int	main(void)
{
	int	ret01;
	int	ret02;

	ret01 = ft_printf("12[%c]8[%%][%s]ewr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X][%d]%w\n",
			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff,
			'A');
	ret02 = printf("12[%c]8[%%][%s]ewr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X][%d]%w\n",
			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff,
			'A');
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%s\n", (char *)NULL);
	ret02 = printf("%s\n", (char *)NULL);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%p\n", NULL);
	ret02 = printf("%p\n", NULL);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%x\n", LONG_MAX); // 24
	ret02 = printf("%x\n", LONG_MAX);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%x\n", LONG_MIN); // 25
	ret02 = printf("%x\n", LONG_MIN);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%x\n", UINT_MAX); // 26
	ret02 = printf("%x\n", UINT_MAX);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%x\n", ULONG_MAX); // 27
	ret02 = printf("%x\n", ULONG_MAX);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	ret01 = ft_printf("%x\n", 9223372036854775807LL); // 28
	ret02 = printf("%x\n", 9223372036854775807LL);
	printf("length : %d\n", ret01);
	printf("length : %d\n", ret02);
	return (EXIT_SUCCESS);
}
