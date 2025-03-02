/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:12:37 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/03 08:22:20 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);
}
