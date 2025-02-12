/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:53:16 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/29 15:27:52 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurrence = NULL;

	while (*str)
	{
		if (*str == (char)c)
			last_occurrence = str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last_occurrence);
}
