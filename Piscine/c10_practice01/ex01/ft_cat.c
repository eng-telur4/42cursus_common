/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:04:30 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/23 08:19:05 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	free_buf(char	*buf, int len)
{
	int i = 0;
	while (i < len)
		buf[i++] = '\0';
}

void	ft_stdio(void)
{
	char	buf[8192];
	while (1)
	{
		read(STDIN_FILENO, buf, sizeof(buf));
		write(STDOUT_FILENO, buf, ft_strlen(buf));
		free_buf(buf, ft_strlen(buf));
	}
}

void	ft_display_file(char *file_name)
{
	int	c;
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	while (read(fd, &c, sizeof(char)) > 0)
		write(STDOUT_FILENO, &c, 1);
	close(fd);
}

void	ft_dislay_files(char **file_names)
{
	int i = 0;
	while (file_names[i] != NULL)
		ft_display_file(file_names[i++]);
}

int	main(int argc, char **argv)
{
	// 引数なし、もしくは引数が単一か２つのダッシュだった場合
	if (argc == 1 || (argc == 2 && (!ft_strcmp(argv[1], "-")
				|| !ft_strcmp(argv[1], "--"))))
	{
		// 標準入力を受取り、そのまま出力する
		ft_stdio();
	}
	else if (argc >= 2)
	{
		ft_dislay_files(&argv[1]);
	}
}