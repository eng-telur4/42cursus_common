/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:24:02 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/21 15:40:27 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}

void	ft_arg_check(int argc)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
	}
	else if (argc >= 3)
	{
		ft_putstr("Too many arguments.\n");
	}

}

int	main(int argc, char **argv)
{
	int	c;
	int	fd;

	ft_arg_check(argc);

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("Cannot read file.\n");
		return 0;
	}
	while (read(fd, &c, sizeof(char)) > 0)
	{
		write(STDOUT_FILENO, &c, 1);
	}
	close(fd);
	return (0);
}
