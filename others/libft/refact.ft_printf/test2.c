#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	write(1, "(1) Hello, World!\n", 18);
	sleep(1);
	printf("(2) Hello, World!");
	sleep(1);
	write(1, "(3) Hello, World!\n", 18);
	sleep(1);
	printf("(4) Hello, World!\n");
	sleep(1);
	printf("BUFSIZ = %d\n", BUFSIZ);
	return (0);
}
