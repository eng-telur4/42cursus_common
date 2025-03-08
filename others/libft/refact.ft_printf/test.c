#include "../ft_printf/ft_printf.h"

int	main(void)
{
	int	ret01;
	int	ret02;

	// 12[A]8[%][BiSH]ewr[123]d[0x402046]f[%][2147483647]32fd[4294967295]wfht43[ff][6FF][65]%w
	ret01 = ft_printf("12[%c]8[%%][%s]ewr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X][%d]%w\n",
			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff,
			'A');
	ret02 = printf("12[%c]8[%%][%s]ewr[%i]d[%p]f[%%][%d]32fd[%u]wfht43[%x][%X][%d]%w\n",
			'A', "BiSH", 123, (void *)"BiSH", INT_MAX, UINT_MAX, 0xFF, 0x6ff,
			'A');
	printf("length : %d\n", ret01);                   // 88
	printf("length : %d\n", ret02);                   // 88
	ret01 = ft_printf("%s\n", (char *)NULL);          // (null)
	ret02 = printf("%s\n", (char *)NULL);             // (null)
	printf("length : %d\n", ret01);                   // 7
	printf("length : %d\n", ret02);                   // 7
	ret01 = ft_printf("%p\n", NULL);                  // (nil)
	ret02 = printf("%p\n", NULL);                     // (nil)
	printf("length : %d\n", ret01);                   // 6
	printf("length : %d\n", ret02);                   // 6
	ret01 = ft_printf("%x\n", LONG_MAX);              // ffffffff
	ret02 = printf("%x\n", LONG_MAX);                 // ffffffff
	printf("length : %d\n", ret01);                   // 9
	printf("length : %d\n", ret02);                   // 9
	ret01 = ft_printf("%x\n", LONG_MIN);              // 0
	ret02 = printf("%x\n", LONG_MIN);                 // 0
	printf("length : %d\n", ret01);                   // 2
	printf("length : %d\n", ret02);                   // 2
	ret01 = ft_printf("%x\n", UINT_MAX);              // ffffffff
	ret02 = printf("%x\n", UINT_MAX);                 // ffffffff
	printf("length : %d\n", ret01);                   // 9
	printf("length : %d\n", ret02);                   // 9
	ret01 = ft_printf("%x\n", ULONG_MAX);             // ffffffff
	ret02 = printf("%x\n", ULONG_MAX);                // ffffffff
	printf("length : %d\n", ret01);                   // 9
	printf("length : %d\n", ret02);                   // 9
	ret01 = ft_printf("%x\n", 9223372036854775807LL); // ffffffff
	ret02 = printf("%x\n", 9223372036854775807LL);    // ffffffff
	printf("length : %d\n", ret01);                   // 9
	printf("length : %d\n", ret02);                   // 9
	return (EXIT_SUCCESS);
}
