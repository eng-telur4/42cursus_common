/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:29:27 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 00:49:59 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

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

void	free_fct(void *ptr)
{
	if (ptr)
		ptr = NULL;
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;

	current = begin_list;
	while (current->next)
	{
		next = current->next;
		free_fct(current->data);
		free(current);
		current = next;
	}
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
	ft_list_clear(ret_val, free_fct);
	now = ret_val;
	printf("%s\n", (char *)now->data);
	while (now->next)
	{
		now = now->next;
		printf("%s\n", (char *)now->data);
	}
}
