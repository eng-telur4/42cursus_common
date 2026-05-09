/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:05:25 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/08 12:29:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum t_bool
{
	FALSE,
	TRUE
}		t_bool;

t_bool	is_alpha_or_numeric(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c
			&& c <= '9'));
}

char	to_uppercase(char c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}

char	to_lowercase(char c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	str_count;

	i = 0;
	str_count = 0;
	while (str[i] != '\0')
	{
		if (is_alpha_or_numeric(str[i]))
		{
			str_count++;
			if (str_count == 1)
				str[i] = to_uppercase(str[i]);
			else
				str[i] = to_lowercase(str[i]);
		}
		else
		{
			if (str_count != 0)
				str_count = 0;
			i++;
			continue ;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str1[] = "salut,"
// 					" comment tu vas ? 42mots quarante-deux; cinquante+et+un";
// 	char *str2;

// 	printf("%s\n", str1);
// 	str2 = ft_strcapitalize(str1);
// 	printf("%s\n", str2);
// }