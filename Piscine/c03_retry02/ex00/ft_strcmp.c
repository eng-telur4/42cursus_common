/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:23:41 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/21 20:01:49 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d, ", ft_strcmp("ABC", "ABC")); // s1 = s2で 0
// 	printf("%d\n", strcmp("ABC", "ABC"));
// 	printf("%d, ", ft_strcmp("ABC", "ABD")); // s1 < s2 で負の値
// 	printf("%d\n", strcmp("ABC", "ABD"));
// 	printf("%d, ", ft_strcmp("ABC", "B")); // s1 < s2 で負の値
// 	printf("%d\n", strcmp("ABC", "B"));
// 	printf("%d, ", ft_strcmp("ABC", "AAAA")); // s1 > s2 で正の値
// 	printf("%d\n", strcmp("ABC", "AAAA"));
// 	printf("%d, ", ft_strcmp("ABC", "ABCD")); // s1 < s2 で負の値
// 	printf("%d\n", strcmp("ABC", "ABCD"));
// 	printf("%d, ", ft_strcmp("ABCD", "ABC")); // s1 > s2 で正の値
// 	printf("%d\n", strcmp("ABCD", "ABC"));
// }