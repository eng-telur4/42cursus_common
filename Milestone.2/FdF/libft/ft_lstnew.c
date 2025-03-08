/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:01:51 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/27 17:22:54 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
