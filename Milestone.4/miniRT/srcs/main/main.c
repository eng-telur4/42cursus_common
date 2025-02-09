/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:31:39 by rpinto-r          #+#    #+#             */
/*   Updated: 2025/02/09 20:54:25 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	msg_quit(char *s)
{
	ft_putendl_fd(s, 1);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_rt	*rt;

	rt = ft_calloc(sizeof(t_rt), 1);
	if (argc != 2)
		show_error(MSG_USAGE);
	else if (open_file(rt, argv[1]))
	{
		rt_init(rt, argv[1]);
		render(rt);
		mlx_loop(rt->mlx);
	}
	rt_free(rt);
	return (0);
}
