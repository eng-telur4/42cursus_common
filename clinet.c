#define BUFSIZE 1000

#include <netdb.h>
#include <netinet/in.h> // htons
#include <stdio.h>      // perror
#include <sys/fcntl.h>
#include <sys/socket.h> // socket, connect
#include <sys/types.h>

int	main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	server_addr;
	char				buf[BUFSIZE];
	int					buf_len;

	// ソケットの生成
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("ERR: socket");
		exit(1);
	}
	// サーバのアドレス・ポート番号を設定
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = inet_addr("10.1.1.102");
	// 上の行のアドレスを各自の実行環境におけるサーバのアドレスに設定
	server_addr.sin_port = htons(8000);
	// ソケットをサーバに接続
	if (connect(sockfd, (struct sockaddr *)&server_addr,
			sizeof(server_addr)) > 0)
	{
		perror("ERR: connect");
		close(sockfd);
		exit(1);
	}
	// ユーザからの文字列の読み取り
	buf_len = read(0, buf, BUFSIZE);
	// メッセージの送信と受信
	write(sockfd, buf, buf_len);
	read(sockfd, buf, BUFSIZE);
	write(1, buf, buf_len);
	// ソケットを閉じる
	close(sockfd);
}
