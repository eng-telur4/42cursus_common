/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ret_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:54:22 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/11 23:05:41 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*ret_val;

	// do memory allocation and check
	ret_val = (t_list *)malloc(sizeof(t_list));
	if (!ret_val)
		return (NULL);
	// assigns values to the struct variables
	ret_val->data = data;
	ret_val->next = NULL;
	// Returns the created ret_valent
	return (ret_val);
}

// int	main(void)
// {
// 	int		a;
// 	t_list	*list;

// 	a = 42;
// 	// リストを作成
// 	list = ft_create_elem(&a);
// 	printf("Value of elem->data: %d\n", *(int *)list->data);
// 	printf("Value of elem->next: %p\n", (void *)list->next);
// 	free(list);
// }
