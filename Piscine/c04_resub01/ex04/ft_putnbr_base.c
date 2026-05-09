/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:37:14 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 12:35:19 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_base(int nbr, char *base, int len)
{
	if (nbr == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar(base[nbr / ft_recursive_power(10, 9) * -1]);
		put_base(nbr % ft_recursive_power(10, 9) * -1, base, len);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		put_base(nbr, base, len);
	}
	else if (nbr >= len)
	{
		put_base(nbr / len, base, len);
		put_base(nbr % len, base, len);
	}
	else
		ft_putchar(base[nbr]);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	result;
	int	len;

	len = 0;
	while (base[len])
		len += 1;
	result = check_base(base);
	if (result)
		put_base(nbr, base, len);
}

// int	main(void)
// {
// 	char	decimal_base[] = "0123456789";
// 	char	binary_base[] = "01";
// 	char	hexadecimal_base[] = "0123456789ABCDEF";
// 	char	octal_base[] = "poneyvif";
// 	char	fiction_base1[] = "";
// 	char	fiction_base2[] = "0";
// 	char	fiction_base3[] = "00";
// 	char	fiction_base4[] = "0+";

// 	ft_putnbr_base(10, decimal_base);
// 	printf("\n");
// 	ft_putnbr_base(5, binary_base);
// 	printf("\n");
// 	ft_putnbr_base(54, hexadecimal_base);
// 	printf("\n");
// 	ft_putnbr_base(39, octal_base);
// 	printf("\n");
// 	ft_putnbr_base(39, fiction_base1);
// 	printf("\n");
// 	ft_putnbr_base(39, fiction_base2);
// 	printf("\n");
// 	ft_putnbr_base(39, fiction_base3);
// 	printf("\n");
// 	ft_putnbr_base(39, fiction_base4);
// 	printf("\n");
// 	ft_putnbr_base(-10, decimal_base);
// 	printf("\n");
// 	ft_putnbr_base(INT_MAX, decimal_base);
// 	printf("\n");
// 	ft_putnbr_base(INT_MIN, decimal_base);
// 	printf("\n");
// }
