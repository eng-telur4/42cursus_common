/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:36:23 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/11 23:40:11 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*now;

	now = begin_list;
	while (now->next)
	{
		now = now->next;
	}
	return (now);
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
	printf("%d\n", *(int *)ft_list_last(linked_list)->data);
}
