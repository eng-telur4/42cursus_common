/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:24:02 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/17 08:28:33 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILENAME "a.cpp"

int	main(void)
{
	int	c;
	int	fd;

	if ((fd = open(FILENAME, O_RDONLY)) == -1)
	{
		fprintf(stderr, "Error: cannot open \"%s\".\n", FILENAME);
		exit(1);
	}
	while (read(fd, &c, sizeof(char)) > 0)
	{
		putchar(c);
	}
	if (close(fd) == -1)
	{
		fprintf(stderr, "Error: cannot close \"%s\".\n", FILENAME);
		exit(2);
	}
	return (0);
}
