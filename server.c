/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:56:34 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/28 16:17:53 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFSIZE 1000

char	*StrToUpper(char *);

#include <ctype.h> // toupper
#include <netdb.h>
#include <netinet/in.h> // sockaddr_in, htonl, htons
#include <stdio.h> // perror
#include <stdlib.h> // exit
#include <strings.h> // bzero
#include <sys/fcntl.h>
#include <sys/socket.h> // socket, bind, listen, accept
#include <sys/types.h>

int	main(void)
{
	int					sockfd;
	int					new_sockfd;
	int					writer_len;
	struct sockaddr_in	reader_addr;
	struct sockaddr_in	writer_addr;
	char				buf[BUFSIZE];
	int					buf_len;

	// ソケットの生成
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("ERR: socket");
		exit(1);
	}
	// 通信ボード・アドレスの設定
	bzero(&reader_addr, sizeof(reader_addr));
	reader_addr.sin_family = PF_INET;
	reader_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	reader_addr.sin_port = htons(8000);
	// ソケットにアドレスを割り当てる
	if (bind(sockfd, (struct sockaddr *)&reader_addr, sizeof(reader_addr)) < 0)
	{
		perror("ERR: bind");
		exit(1);
	}
	// ソケットを接続待ちモードとする
	if (listen(sockfd, 3) < 0)
	{
		close(sockfd);
		perror("ERR: listen");
		exit(1);
	}
	// 接続要求を待つ
	if ((new_sockfd = accept(sockfd, (struct sockaddr *)&writer_addr,
				&writer_len)) < 0)
	{
		perror("ERR: accept");
		exit(1);
	}
	// メッセージの受信と送信
	buf_len = read(new_sockfd, buf, BUFSIZE);
	write(1, buf, buf_len);
	write(new_sockfd, StrToUpper(buf), buf_len);
	// ソケットを閉じる
	close(new_sockfd);
	close(sockfd);
}

// 文字列中の小文字を大文字に変換する関数
char	*StrToUpper(char *s)
{
	char	*t;

	for (t = s; *t; t++)
	{
		*t = toupper(*t);
	}
	return (s);
}
