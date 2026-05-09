/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:28:59 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/11 23:35:42 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	t_list	*now;
	int		count;

	now = begin_list;
	count = 1;
	while (now->next)
	{
		count++;
		now = now->next;
	}
	return (count);
}

int	main(void)
{
	t_list *linked_list;
	int a;
	int b;
	int c;
	void *p1;
	void *p2;
	void *p3;

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
	printf("%d\n", ft_list_size(linked_list));
}