/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/11/01 18:01:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef enum e_type
{
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INTEGER,
	UNSIGNED,
	LOWER_HEX,
	UPPER_HEX,
	PERCENT,
	OTHER
}			t_type;

typedef enum e_flags
{
	MINUS,
	PLUS,
	ZERO,
	SPACE,
	HASHTAG,
	OTHER
}			t_flags;

typedef struct s_format
{
	t_type	type;
	t_bool	dot;
	int		precision;
	int		width;
	t_flags	flags;
}			t_format;

char	**format_split(const char *str)
{
}

t_type	judge_format_type(char c)
{
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'd')
		return (DECIMAL);
	if (c == 'i')
		return (INTEGER);
	if (c == 'u')
		return (UNSIGNED);
	if (c == 'x')
		return (LOWER_HEX);
	if (c == 'X')
		return (UPPER_HEX);
	if (c == '%')
		return (PERCENT);
	return (OTHER);
}

t_format	*format_new(const char *str)
{
	t_format	*ret;
	int			i;

	ret = (t_format *)malloc(sizeof(t_format));
	i = 0;
	if (str[i] == '%')
		i++;
	ret->type = judge_format_type(str[i]);
	return (ret);
}

// 文字列の長さを取得する
size_t		ft_strlen(const char *s);
// 文字列を標準出力に表示する
int			ft_putstr_fd(char *s, int fd);
// 文字を標準出力に表示する
int			ft_putchar_fd(char c, int fd);
// 文字が「%」かどうか判定する
t_bool		is_percent(char c);
// 整数を文字列に変換するitoa関数のunsigned long long版
char		*ft_itoa_ull(unsigned long long val, char *a, char *base,
				unsigned long long radix);
// 整数を標準出力に表示する(int)
int			ft_putnbr_fd(int n, int fd);
// 整数を標準出力に表示する(unsigned int)
int			ft_putnbr_fd_u(unsigned int n, int fd);
// 整数を標準出力に表示する(long long型、進数対応)
int			ft_putnbr_fd_base(long long n, char *base, int base_num, int fd);

#endif // LIBFTPRINTF_H
