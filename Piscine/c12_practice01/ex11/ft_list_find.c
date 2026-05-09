/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:40:19 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 14:45:14 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

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

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*now;

	now = begin_list;
	if (!cmp(now->data, data_ref))
		return (now);
	while (now->next)
	{
		now = now->next;
		if (!cmp(now->data, data_ref))
			return (now);
	}
	return (now);
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
	printf("%s\n", (char *)ft_list_find(ret_val, "new", ft_strcmp)->data);
}
