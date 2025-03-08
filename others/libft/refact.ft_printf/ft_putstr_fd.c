/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:39:24 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/09 02:37:23 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	ret;
	int	tmp;

	ret = 0;
	while (*s)
	{
		tmp = ft_putchar_fd(*s, fd);
		if (tmp)
			ret += tmp;
	}
	return (ret);
}
