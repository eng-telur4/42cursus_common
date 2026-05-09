/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:21:45 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 18:38:49 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
		if (f(tab[i++]) != 0)
			count++;
	return (count);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_is_len_five(char *str)
{
	if (ft_strlen(str) == 5)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	*strs[] = {"hello", "brand", "new", "world"};

// 	printf("%d\n", ft_count_if(strs, 4, ft_is_len_five));
// }
