/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:12:37 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/03 09:25:17 by skamijo          ###   ########.fr       */
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
	// ESC keyを押すとウィンドウを閉じる
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	isometric_projection(float x, float y, float z, float *x2d, float *y2d)
{
	*x2d = 0.866f * x - 0.866f * y;
	*y2d = 0.5f * x + 0.5f * y + z;
}

int	main(void)
{
	t_vars	vars;
	float	x;
	float	y;
	float	z;

	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	float x2d, y2d;
	isometric_projection(x, y, z, &x2d, &y2d);
	printf("3D座標 (%.2f, %.2f, %.2f) -> 2D座標 (%.2f, %.2f)\n", x, y, z, x2d, y2d);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 950, 950, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);
}
