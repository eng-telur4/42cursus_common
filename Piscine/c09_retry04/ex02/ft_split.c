/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:36:53 by totake            #+#    #+#             */
/*   Updated: 2024/09/22 13:35:36 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char *str, int start, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_c_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_start_end(char *str, char *charset, int *j, int flag)
{
	if (flag)
	{
		while (str[*j] && ft_c_is_charset(str[*j], charset))
			*j = *j + 1;
		return (*j);
	}
	else
	{
		while (str[*j] && !ft_c_is_charset(str[*j], charset))
			*j = *j + 1;
		return (*j);
	}
}

int	ft_strs_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_c_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_c_is_charset(str[i], charset))
			count++;
		while (str[i] && !ft_c_is_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		j;
	int		start;
	int		strs_count;

	i = 0;
	j = 0;
	strs_count = ft_strs_count(str, charset);
	ret = (char **)malloc(sizeof(char *) * (strs_count + 1));
	if (!str || !ret)
		return (NULL);
	while (i < strs_count)
	{
		start = find_start_end(str, charset, &j, 1);
		ret[i] = ft_substr(str, start, find_start_end(str, charset, &j, 0)
				- start);
		if (!ret[i])
		{
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

// int	main(int argc, char **argv)
// {
// 	char	**ret;
// 	int		i;

// 	(void)argc;
// 	i = 0;
// 	ret = ft_split(argv[1], argv[2]);
// 	// ret = ft_split("//abc|cdefg|/hij|", "/|");
// 	while (ret[i])
// 	{
// 		printf("%s\n", ret[i]);
// 		i++;
// 	}
// 	return (0);
// }
