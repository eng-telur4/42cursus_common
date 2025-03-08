/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:37:34 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/27 17:26:46 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_2d(void **arr, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
		free(arr[k--]);
	free(arr);
}

static int	find_start(char const *s, char c, int *j)
{
	while (s[*j] && s[*j] == c)
		*j = *j + 1;
	return (*j);
}

static int	find_end(char const *s, char c, int *j)
{
	while (s[*j] && s[*j] != c)
		*j = *j + 1;
	return (*j);
}

static int	ft_strs_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		start;
	int		strs_count;

	i = 0;
	j = 0;
	strs_count = ft_strs_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (strs_count + 1));
	if (!s || !ret)
		return (NULL);
	while (i < strs_count)
	{
		start = find_start(s, c, &j);
		ret[i] = ft_substr(s, start, find_end(s, c, &j) - start);
		if (!ret[i])
		{
			free_2d((void **)ret, i);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
