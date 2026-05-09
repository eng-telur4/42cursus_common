/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:28:06 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/23 03:23:46 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_itoa_ull(unsigned long long val, char *a, char *base,
		unsigned long long radix)
{
	char				*p;
	unsigned long long	v;
	unsigned long long	n;

	p = a;
	v = val;
	n = 1;
	while (v >= radix)
	{
		v /= radix;
		n++;
	}
	p = a + n;
	v = val;
	*p = '\0';
	--p;
	*p = base[v % radix];
	v /= radix;
	while (p != a)
	{
		--p;
		*p = base[v % radix];
		v /= radix;
	}
	return (a);
}

void	print_addr(void *addr)
{
	char			a[17];
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	ft_itoa_ull((unsigned long long)addr, a, "0123456789abcdef", 16);
	while (a[len] != '\0')
		len++;
	while (i++ < 16 - len)
		write(STDOUT_FILENO, "0", 1);
	write(STDOUT_FILENO, a, len);
	write(STDOUT_FILENO, ": ", 2);
}

void	view_hex(char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i + 1 <= size)
	{
		write(STDOUT_FILENO, &("0123456789abcdef"[addr[i] / 16]), 1);
		write(STDOUT_FILENO, &("0123456789abcdef"[addr[i] % 16]), 1);
		if (i % 2 == 1)
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(STDOUT_FILENO, "  ", 2);
		if (i % 2 == 1)
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
}

void	print16(char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && (i + 1) <= size)
	{
		if (32 <= addr[i] && addr[i] <= 126)
			write(STDOUT_FILENO, &addr[i], 1);
		else
			write(STDOUT_FILENO, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i != size / 16 + 1)
	{
		print_addr(&addr[16 * i]);
		view_hex((char *)&addr[16 * i], size - (16 * i));
		print16((char *)&addr[16 * i], size - (16 * i));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (addr);
}

// int	main(void)
// {
// 	char str[] = "Bonjour les amin"
// 					"ches\t\n\tc\a est fo"
// 					"u\ttout\tce qu on "
// 					"peut faire avec\t"
// 					"\n\tprint_memory\n\n"
// 					"\n\tlol.lol\n ";
// 	ft_print_memory(str, 92);
// }
