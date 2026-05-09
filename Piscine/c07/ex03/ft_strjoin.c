/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:45:12 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/15 19:42:58 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int		dest_len;
	char	*tmp;

	tmp = dest;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret_val;
	int		count;
	int		i;
	int		j;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	count = 0;
	i = 0;
	while (i < size)
		count += ft_strlen(strs[i++]);
	count += size;
	ret_val = (char *)malloc(count * sizeof(char));
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcat(ret_val, strs[i]);
		if (i != size - 1)
			ft_strcat(ret_val, sep);
		i++;
	}
	return (ret_val);
}

// int	main(void)
// {
// 	char	*str[] = {"Hello", "brand", "new", "world"};
// 	printf("%s\n", ft_strjoin(4, str, " "));
// }
