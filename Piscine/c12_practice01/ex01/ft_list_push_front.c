/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:00:32 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/11 23:18:23 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	if (*begin_list)
	{
		node = ft_create_elem(data);
		node->next = *begin_list;
		*begin_list = node;
	}
	else
		*begin_list = ft_create_elem(data);
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
	int		d;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;

	linked_list = (t_list *)malloc(sizeof(t_list));
	// declaration of values
	a = 1;
	b = 2;
	c = 3;
	d = 42;
	// declaration and assign of pointers
	p1 = &a;
	p2 = &b;
	p3 = &c;
	p4 = &d;
	// Creation of List Elements
	linked_list = ft_create_elem(p1);
	linked_list->next = ft_create_elem(p2);
	linked_list->next->next = ft_create_elem(p3);
	printf("Linked list before:\n");
	print_list(linked_list);
	// Insert a new element at the beginning of the linked list
	ft_list_push_front(&linked_list, p4);
	printf("\nLinked list after:\n");
	print_list(linked_list);
	// free of memory allocated
	free(linked_list);
}
