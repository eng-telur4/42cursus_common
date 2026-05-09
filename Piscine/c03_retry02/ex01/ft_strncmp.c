/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:23:41 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:48:43 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

int	main(void)
{
	char str[] = "ABC";

	// s1 = s2で 0
	printf("%d, %d\n", ft_strncmp(str, "ABD", 2), strncmp(str, "ABD", 2));
	// s1 = s2で 0
	printf("%d, %d\n", ft_strncmp(str, "ABC", 2), strncmp(str, "ABC", 2));
	// s1 > s2 で正の値
	printf("%d, %d\n", ft_strncmp(str, "AAA", 2), strncmp(str, "AAA", 2));
	// s1 = s2で 0
	printf("%d, %d\n", ft_strncmp(str, "ABCD", 2), strncmp(str, "ABCD", 2));
	// s1 = s2で 0
	printf("%d, %d\n", ft_strncmp(str, "AB", 2), strncmp(str, "AB", 2));
	// s1 < s2 で負の値
	printf("%d, %d\n", ft_strncmp(str, "B", 2), strncmp(str, "B", 2));
	// s1 > s2 で正の値
	printf("%d, %d\n", ft_strncmp(str, "A", 2), strncmp(str, "A", 2));
}