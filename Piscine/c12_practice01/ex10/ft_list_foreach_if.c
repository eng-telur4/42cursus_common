/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:09:32 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 14:39:26 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <unistd.h>

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*now;

	now = begin_list;
	if (!cmp(now->data, data_ref))
		f(now->data);
	while (now->next)
	{
		now = now->next;
		if (!cmp(now->data, data_ref))
			f(now->data);
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
	ft_list_foreach_if(ret_val, (void *)ft_putstr, "new", ft_strcmp);
}
