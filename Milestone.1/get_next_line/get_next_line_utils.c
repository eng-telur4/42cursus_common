/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:42:25 by skamijo           #+#    #+#             */
/*   Updated: 2024/11/26 08:43:31 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		del(current->content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*now;

	if (!lst)
		return ;
	now = lst;
	f(now->content);
	while (now->next)
	{
		now = now->next;
		f(now->content);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*now;

	if (!lst)
		return (0);
	now = lst;
	while (now->next)
		now = now->next;
	return (now);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ret_val;

	ret_val = (t_list *)malloc(sizeof(t_list));
	if (!ret_val)
		return (NULL);
	ret_val->content = content;
	ret_val->next = NULL;
	return (ret_val);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*now;
	int		count;

	if (!lst)
		return (0);
	now = lst;
	count = 1;
	while (now->next)
	{
		count++;
		now = now->next;
	}
	return (count);
}
