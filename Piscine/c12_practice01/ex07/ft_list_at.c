/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:50:39 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 00:55:42 by skamijo          ###   ########.fr       */
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

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*now;
	unsigned int	i;

	i = 0;
	now = begin_list;
	while (now->next)
	{
		now = now->next;
		i++;
		if (nbr == i)
			return (now);
	}
	return (NULL);
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
	printf("%s\n", (char *)ft_list_at(ret_val, 1)->data);
	printf("%s\n", (char *)ft_list_at(ret_val, 3)->data);
	printf("%s\n", (char *)ft_list_at(ret_val, 5)->data);
}
