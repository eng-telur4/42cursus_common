/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:24:52 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/13 19:24:53 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILENAME "output.txt"
#define STR "open2.c\n"

int	main(void)
{
	int fd;

	if ((fd = open(FILENAME, O_WRONLY | O_CREAT)) == -1)
	{
		fprintf(stderr, "Error: cannot open \"%s\".\n", FILENAME);
		exit(1);
	}

	write(fd, STR, sizeof(STR));

	if (close(fd) == -1)
	{
		fprintf(stderr, "Error: cannot close \"%s\".\n", FILENAME);
		exit(2);
	}

	return (0);
}