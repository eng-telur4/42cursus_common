/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:29:54 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/26 18:38:44 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		if (f(tab[i++]) != 0)
			return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_is_len_three(char *str)
{
	if (ft_strlen(str) == 3)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	*strs[] = {"hello", "brand", "new", "world"};

// 	printf("%d\n", ft_any(strs, ft_is_len_three));
// }
