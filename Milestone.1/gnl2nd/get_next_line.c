/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:54:29 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/18 15:05:02 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// gcc -D BUFFER_SIZE=1024 -o my_program my_program.c

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

static char	*read_from_file(char *basin_buffer, int fd)
{
	ssize_t	bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		// fdファイルをからBUFFER_SIZE分をbufferに読み込む(戻り値：成功時に読み込んだバイト数
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free(cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

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
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
	{
		free(basin_buffer);
		return (NULL);
	}
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}
