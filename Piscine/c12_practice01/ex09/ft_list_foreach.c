/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:43 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 14:08:55 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	to_double(int *n)
{
	*n = *n * 2;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*now;

	now = begin_list;
	f(now->data);
	while (now->next)
	{
		now = now->next;
		f(now->data);
	}
}

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current != NULL)
	{
		printf("Value: %d\n", *(int *)current->data);
		current = current->next;
	}
}

int	main(void)
{
	t_list	*linked_list;
	int		a;
	int		b;
	int		c;
	void	*p1;
	void	*p2;
	void	*p3;

	linked_list = (t_list *)malloc(sizeof(t_list));
	// declaration of values
	a = 1;
	b = 2;
	c = 3;
	// declaration and assign of pointers
	p1 = &a;
	p2 = &b;
	p3 = &c;
	// Creation of List Elements
	linked_list = ft_create_elem(p1);
	linked_list->next = ft_create_elem(p2);
	linked_list->next->next = ft_create_elem(p3);
	print_list(linked_list);
	ft_list_foreach(linked_list, (void *)to_double);
	print_list(linked_list);
}
