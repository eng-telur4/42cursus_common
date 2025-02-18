#include <stddef.h> // NULL
#include <stdint.h> // SIZE_MAX

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3 // デフォルト値
#endif

char	*ft_strchr(const char *s, int c) // ft_free
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*d;
	int		i;

	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2) // ft_free
{
	char *ret;
	size_t total_len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)ft_calloc(total_len, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcat(ret, s1, total_len);
	ft_strlcat(ret, s2, total_len);
	return (ret);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
		*ptr++ = (char)c;
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size) // read_file
{
	void *ptr;

	if (nmemb && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// 独自ヘルパー関数
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// バッファを更新する

// 行を抽出する

// ファイルから内容を読み取る
/**
 * @fn char	*read_file(int fd, char *res)
 * @brief ファイルから内容を読み取り返す関数
 * @param[in] fd 内容を読み取りたいファイルのファイルディスクリプタ
 * @param[out] res ファイルの内容を書き込むためのバッファ(引数でもこのバッファのポインタを返す)
 * @return char * ファイルの内容を書き込んだバッファのポインタ
 * @details
 * バッファresがNULLのっ場合、ft_callocを使用して1バイトで初期化する
 *
 */
char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

// 中心処理
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer); // ファイルから内容を読み取る
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);   // 行を抽出する
	buffer = ft_next(buffer); // バッファを更新する
	return (line);
}

// (1) 永続メモリ：関数が終了すると全てを忘れてしまう通常の変数とは異なり、
// 静的バッファは関数呼び出し間でその内容を記憶する
// (2) 中断したところから再開：このメモリのおかげで、前回停止した場所から読み取りを続行できる
// get_next_lineが呼び出されるたびにファイルの戦闘から開始する必要はない
// (3) 部分読み取りの処理：場合によっては、バッファに複数の行を読み込むことがある
// 静的変数を使用すると、次の関数呼び出しのために余分なデータを保持できるため、情報が失われることはない
//
// 1. 最初の呼び出し
//    - bufferにメモリを割り当て、ファイルを読み込む
//    - 最初の行を抽出して返す
//    - 残ったデータはbufferに残る
// 2. 以降の通話
//    - bufferに前回の残りのデータがまだ含まれている
//    - まず、bufferに完全な行があるかどうか確認する
//    - そうでない場合は、ファイルから更に読み取り、bufferに追加する
//    - 次の行を抽出してbufferを再開する
// 3. ラストコール
//    - ファイルの最後まで到達した
//    - 残りのデータはbufferで返される
//    - bufferを開放してNULLに設定する
//
// - 効率性：各行ごとにファイル全体を再度読み込む必要はなく、中断したところから続行するだけ
// - シンプルさ：静的変数が状態管理を処理する。位置を追跡するためにポインターを渡す必要はない
// - メモリ管理：関数呼び出しごとに新しいメモリを割り当てるのではなく、メモリを一度割り当てて再利用することができる
//
// - 複数のファイル記述子：複数のファイルから読み取る場合は、各ファイル記述子を個別に処理する必要がある
// - メモリ使用量：ファイルの読み取りが完了しても、バッファはプログラムが終了するまで残る
// - スレッドセーフティ：マルチスレッド環境で作業している場合は、これをスレッドセーフにするために特別な注意が必要
