/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:50:17 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/29 11:59:43 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		d = dest;
		s = src;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = (char *)dest + n;
		s = (const char *)src + n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
