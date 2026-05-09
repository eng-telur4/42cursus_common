/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 01:01:55 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 14:00:52 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ret_val;
	int		i;
	t_list	*now;

	i = 0;
	ret_val = ft_create_elem(strs[i]);
	now = ret_val;
	i++;
	while (i < size)
	{
		now->next = ft_create_elem(strs[i]);
		now = now->next;
		i++;
	}
	return (ret_val);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

int	main(void)
{
	char	*strs[] = {"hello", "brand", "new", "world"};
	t_list	*ret_val;
	t_list	*now;

	ret_val = ft_list_push_strs(4, strs);
	now = ret_val;
	printf("%s\n", (char *)now->data);
	while (now->next)
	{
		now = now->next;
		printf("%s\n", (char *)now->data);
	}
	ft_list_reverse(&ret_val);
	now = ret_val;
	printf("%s\n", (char *)now->data);
	while (now->next)
	{
		now = now->next;
		printf("%s\n", (char *)now->data);
	}
}
