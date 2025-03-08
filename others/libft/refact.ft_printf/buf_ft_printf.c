#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/** 整数を文字列に変換する関数 */
void	ft_itoa(int n, char *str)
{
	int		i;
	int		is_negative;
	int		start;
	int		end;
	char	temp;

	i = 0;
	is_negative = 0;
	// 負の数の場合
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	// 数値を逆順に格納
	do
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	} while (n > 0);
	// 負の数の場合、先頭に '-' を追加
	if (is_negative)
	{
		str[i++] = '-';
	}
	// 文字列を逆順に並べ替える
	str[i] = '\0';
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/** バッファリング対応 ft_printf のメイン関数 */
int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*p = format;
	int			num;

	va_start(args, format);
	char temp[32]; // 数値変換用バッファ
	int len, total_len = 0;
	char *buffer = (char *)malloc(BUFSIZ); // バッファを動的に確保
	int buf_index = 0;                     // バッファのインデックス
	if (!buffer)
	{ // メモリ確保失敗時
		va_end(args);
		return (-1);
	}
	while (*p)
	{
		if (*p == '%')
		{ // フォーマット指定子
			p++;
			if (*p == 'd')
			{ // 整数
				num = va_arg(args, int);
				ft_itoa(num, temp); // 整数を文字列に変換
				len = strlen(temp);
				if (buf_index + len >= BUFSIZ)
				{ // バッファが溢れそうならフラッシュ
					write(1, buffer, buf_index);
					buf_index = 0;
				}
				memcpy(&buffer[buf_index], temp, len);
				buf_index += len;
				total_len += len;
			}
			// 他のフォーマット (例: %s, %x) は省略...
		}
		else
		{ // 通常の文字
			buffer[buf_index++] = *p;
			total_len++;
			if (*p == '\n' || buf_index >= BUFSIZ)
			{ // 改行またはバッファが満杯ならフラッシュ
				write(1, buffer, buf_index);
				buf_index = 0;
			}
		}
		p++;
	}
	// 残ったバッファをフラッシュ
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
	}
	free(buffer); // バッファの解放
	va_end(args);
	return (total_len);
}

int	main(void)
{
	// テストケース
	ft_printf("Hello, ");  // 出力されないはず
	sleep(1);              // 出力のタイミングをずらす
	ft_printf("world!\n"); // ここでフラッシュされる
	ft_printf("Buffered output test...");
	sleep(1);
	ft_printf(" this is a buffered text.\n"); // ここでフラッシュされる
	// 複数の整数の表示
	ft_printf("Integer test: %d\n", 42);    // 42 が出力されるはず
	ft_printf("Negative test: %d\n", -256); // -256 が出力されるはず
	return (0);
}
