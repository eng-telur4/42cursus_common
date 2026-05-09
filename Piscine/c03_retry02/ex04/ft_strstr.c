/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:42:07 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/12 19:49:02 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*p1;
	char	*p2;

	p1 = str;
	p2 = to_find;
	while (*p1 && *p2)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
		{
			p1 -= p2 - to_find - 1;
			p2 = to_find;
		}
	}
	if (*p2)
		return (NULL);
	else
		return (p1 - (p2 - to_find));
}

int	main(void)
{
	char	*sp;
	char	s1[] = "abcdefghijklmn";
	char	s2[] = "defgh";
	char	s3[] = "xyz";
	char	s4[] = "abcdefghijklmnopqr";
	char	s5[] = "";

	// 一致する場合はp2から
	// 25行目 : 一致したら、次の文字を比較(次の文字を削る)
	// 30行目 : 一致しなかったら、p1のポインタの位置をp2-s2-1分移動しp2の文字列をもとに戻す
	sp = strstr(s1, s2);
	printf("%s\n", sp);
	sp = ft_strstr(s1, s2);
	printf("%s\n", sp);
	sp = strstr(s1, s3);
	// 一致しない場合はNULLが返却される
	printf("%s\n", sp);
	sp = ft_strstr(s1, s3);
	printf("%s\n", sp);
	sp = strstr(s1, s4);
	// s2がs1よりも長い場合はNULLが返却される
	printf("%s\n", sp);
	sp = ft_strstr(s1, s4);
	printf("%s\n", sp);
	sp = strstr(s1, s5);
	// s2が\0の場合には、s1が返却される
	printf("%s\n", sp);
	sp = ft_strstr(s1, s5);
	printf("%s\n", sp);
	return (0);
	// 参考：https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q12196811072
}
