/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:35:39 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/17 16:41:55 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*ret_val;

	ret_val = (struct s_stock_str *)malloc((ac + 1)
			* sizeof(struct s_stock_str));
	if (ret_val == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret_val[i].size = ft_strlen(av[i]);
		ret_val[i].str = av[i];
		ret_val[i].copy = (char *)malloc((ret_val[i].size + 1) * sizeof(char));
		if (ret_val[i].copy == NULL)
			return (NULL);
		ft_strcpy(ret_val[i].copy, av[i]);
		i++;
	}
	ret_val[i].str = 0;
	return (ret_val);
}

// int	main(void)
// {
// 	char				*strs[] = {"hello", "brand", "new", "world"};
// 	struct s_stock_str	*s_stock;
// 	int					i;

// 	s_stock = ft_strs_to_tab(4, strs);
// 	i = 0;
// 	while (s_stock[i].size)
// 	{
// 		printf("size : %d, str : %s, copy : %s\n", s_stock[i].size,
// 			s_stock[i].str, s_stock[i].copy);
// 		printf("strs addr : %p, str addr : %p, copy addr : %p\n", strs[i],
// 			s_stock[i].str, s_stock[i].copy);
// 		i++;
// 	}
// }
