/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:11 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/12 22:10:10 by skamijo          ###   ########.fr       */
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
	T_CHAR,
	T_STRING,
	T_POINTER,
	T_DECIMAL,
	T_INTEGER,
	T_UNSIGNED,
	T_LOWER_HEX,
	T_UPPER_HEX,
	T_PERCENT,
	T_OTHER
}			t_type;

typedef enum e_flags
{
	F_MINUS,
	F_PLUS,
	F_ZERO,
	F_SPACE,
	F_HASHTAG,
	F_OTHER
}			t_flags;

typedef struct s_format
{
	t_flags	flags;
	int		width;
	t_bool	dot;
	int		precision;
	t_type	type;
}			t_format;

//
int			ft_printf(const char *str, ...);
// 文字が数字かどうか
int			ft_isdigit(int c);
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
