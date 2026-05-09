/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:07:59 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 18:39:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include <stdio.h>

int	ft_is_all_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_do_op(char *n1, char *op, char *n2, int (*p[])(int, int))
{
	if (!ft_strcmp(op, "+"))
		return (p[0](ft_atoi(n1), ft_atoi(n2)));
	else if (!ft_strcmp(op, "-"))
		return (p[1](ft_atoi(n1), ft_atoi(n2)));
	else if (!ft_strcmp(op, "*"))
		return (p[2](ft_atoi(n1), ft_atoi(n2)));
	else if (!ft_strcmp(op, "/"))
		return (p[3](ft_atoi(n1), ft_atoi(n2)));
	else if (!ft_strcmp(op, "%"))
		return (p[4](ft_atoi(n1), ft_atoi(n2)));
	return (0);
}

int	main(int argc, char **argv)
{
	int	(*p[5])(int, int);

	p[0] = ft_add;
	p[1] = ft_sub;
	p[2] = ft_mul;
	p[3] = ft_div;
	p[4] = ft_mod;
	if (argc == 4)
	{
		if (ft_atoi(argv[3]) == 0 && ft_is_all_zero(argv[3]))
		{
			if (!ft_strcmp(argv[2], "/"))
				ft_putstr("division by zero\n");
			else if (!ft_strcmp(argv[2], "%"))
				ft_putstr("modulo by zero\n");
			else
				printf("0\n");
		}
		else
			printf("%d\n", ft_do_op(argv[1], argv[2], argv[3], p));
	}
}
