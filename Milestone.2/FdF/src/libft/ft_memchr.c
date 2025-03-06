/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:54:41 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/29 14:32:03 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*sp;
	unsigned char	uc;

	sp = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len > 0)
	{
		if (*sp == uc)
			return (sp);
		len--;
		sp++;
	}
	return (NULL);
}
