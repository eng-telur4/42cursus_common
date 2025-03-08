/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:05:29 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/27 17:22:56 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*now;
	int		count;

	if (!lst)
		return (0);
	now = lst;
	count = 1;
	while (now->next)
	{
		count++;
		now = now->next;
	}
	return (count);
}
