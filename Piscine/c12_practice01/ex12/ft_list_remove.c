/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:55:21 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:46:02 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list *begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*now;
	t_list	*next;
	t_list	*prev;

	now = begin_list;
	if (!cmp(now->data, data_ref))
	{
		next = now->next;
		free_fct(now->data);
		free(now);
		now = next;
	}
	while (now->next)
	{
		prev = now;
		now = now->next;
		if (!cmp(now->data, data_ref))
		{
			prev->next = now->next;
			next = now->next;
			free_fct(now->data);
			free(now);
			now = next;
		}
	}
}
