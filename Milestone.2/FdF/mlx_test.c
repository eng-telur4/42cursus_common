/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:37:48 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/02 00:34:16 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

// int	event_handler(int key, void *mlx)
// {
// 	(void)key;
// 	(void)mlx;
// 	printf("called\n");
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 300, 300, "Hello World");
// 	mlx_hook(mlx_win, KeyPress, KeyPressMask, event_handler, mlx);
// 	mlx_loop(mlx);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 300, 300, "Hello World");
// 	mlx_loop(mlx);
// 	(void)mlx_win;
// }

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// メモリのオフセットを計算する関数
// t_dataのline_lengthは実際のウィンドウの幅とは異なる
// これは、画像データがメモリに配置される方法に関連している
// 画像データは、各行が特定のバイト数で終了するように配置される
// このバイト数は、line_lengthで指定される
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void		draw_square(t_data *data, int x, int y, int color);
void		draw_circle(t_data *data, int x, int y, int radius, int color);
void		draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);
void		draw_triangle(t_data *data, int x0, int y0, int x1, int y1, int x2,
				int y2, int color);
void		draw_hexagon(t_data *data, int x, int y, int size, int color);
void		draw_square_gradation(t_data *data, int x, int y);
void		draw_rainbow(t_data *data, int x, int y);
int			generate_argb(int a, int r, int g, int b);

#define WIDTH 1000
#define HEIGHT 950

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	// void	*img;
	// このコードを実行しても何も表示されず、何も描画されない
	// まだウィンドウを作成していないから
	mlx = mlx_init();
	// mlx_new_window関数：ウィンドウを作成し、そのウィンドウへのポインタを返す
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	// mlx_new_image関数：画像を作成し、その画像へのポインタを返す
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// 画像を作成した後、mlx_get_data_addr関数を使って画像のメモリアドレスを取得する
	// これで画像のアドレスは得られたが、まだピクセルではない(何も描画されない)
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// メモリオフセットを計算する
	// 引数：画像データ、x座標、y座標、色
	my_mlx_pixel_put(&img, 0, 0, generate_argb(0, 255, 0, 0));
	draw_square(&img, 100, 100, generate_argb(0, 0, 255, 0));
	draw_circle(&img, 300, 300, 50, generate_argb(0, 0, 0, 255));
	draw_triangle(&img, 500, 500, 600, 600, 550, 450, generate_argb(0, 255, 255,
			0));
	draw_hexagon(&img, 900, 100, 100, generate_argb(0, 255, 0, 255));
	draw_line(&img, 70, 700, 700, 70, generate_argb(0, 0, 255, 255));
	draw_square_gradation(&img, 700, 700);
	draw_rainbow(&img, 800, 800);
	// mlx_put_image_to_window関数：ウィンドウに画像を表示する
	// 引数：mlx、ウィンドウへのポインタ、画像へのポインタ、x座標、y座標
	// 1つのウィンドウに1つの画像を全画面表示するばあい、x座標とy座標は0に設定する
	// その代わり、その1つの画像の位置を変えたい場合はmy_mlx_pixel_put関数のx座標とy座標を変更する
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// ウィンドウの描画を開始するために、mlx_loop関数を呼び出す
	mlx_loop(mlx);
	// (void)mlx;
	// (void)mlx_win;
	// (void)img;
}

int	generate_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

#include <math.h>
#include <stdlib.h>

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;

	// Draw top and bottom edges
	for (i = 0; i < 100; i++)
	{
		my_mlx_pixel_put(data, x + i, y, color);
		my_mlx_pixel_put(data, x + i, y + 100, color);
	}
	// Draw left and right edges
	for (i = 0; i <= 100; i++)
	{
		my_mlx_pixel_put(data, x, y + i, color);
		my_mlx_pixel_put(data, x + 100, y + i, color);
	}
}

void	draw_circle(t_data *data, int x, int y, int radius, int color)
{
	int		i;
	int		j;
	double	dist;

	for (i = -radius; i <= radius; i++)
	{
		for (j = -radius; j <= radius; j++)
		{
			dist = sqrt(i * i + j * j);
			if (dist >= radius - 1 && dist <= radius + 1)
				my_mlx_pixel_put(data, x + i, y + j, color);
		}
	}
}

// Function to draw a line using Bresenham's line algorithm
void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		my_mlx_pixel_put(data, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

// Function to draw a triangle based on three vertices
void	draw_triangle(t_data *data, int x0, int y0, int x1, int y1, int x2,
		int y2, int color)
{
	int	min_y;
	int	max_y;
	int	min_x;
	int	max_x;
	int	x;
	int	y;

	// Draw the edges of the triangle
	draw_line(data, x0, y0, x1, y1, color);
	draw_line(data, x1, y1, x2, y2, color);
	draw_line(data, x2, y2, x0, y0, color);
	// Fill the triangle (simple scanline fill algorithm)
	min_y = fmin(fmin(y0, y1), y2);
	max_y = fmax(fmax(y0, y1), y2);
	for (y = min_y; y <= max_y; y++)
	{
		min_x = 1920;
		max_x = 0;
		if (y1 != y0 && y >= y0 && y <= y1)
		{
			x = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
			if (x < min_x)
				min_x = x;
			if (x > max_x)
				max_x = x;
		}
		if (y2 != y1 && y >= y1 && y <= y2)
		{
			x = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
			if (x < min_x)
				min_x = x;
			if (x > max_x)
				max_x = x;
		}
		if (y0 != y2 && y >= y2 && y <= y0)
		{
			x = x2 + (x0 - x2) * (y - y2) / (y0 - y2);
			if (x < min_x)
				min_x = x;
			if (x > max_x)
				max_x = x;
		}
		for (x = min_x; x <= max_x; x++)
		{
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

// Function to draw a hexagon based on the center position and size
void	draw_hexagon(t_data *data, int x, int y, int size, int color)
{
	int		i;
	double	angle;

	int x0, y0, x1, y1;
	for (i = 0; i < 6; i++)
	{
		angle = M_PI / 3 * i;
		x0 = x + size * cos(angle);
		y0 = y + size * sin(angle);
		angle = M_PI / 3 * (i + 1);
		x1 = x + size * cos(angle);
		y1 = y + size * sin(angle);
		draw_line(data, x0, y0, x1, y1, color);
	}
}

void	draw_square_gradation(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	gradation;

	for (i = 0; i < 100; i++)
	{
		gradation = 255 * i / 100;
		for (j = 0; j < 100; j++)
		{
			my_mlx_pixel_put(data, x + i, y + j,
				gradation << 16 | gradation << 8 | gradation);
		}
	}
}

void	draw_rainbow(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	for (i = 0; i < 100; i++)
	{
		if (i < (100 / 7 * 1))
			color = 0xFF0000; // Red
		else if (i < (100 / 7 * 2))
			color = 0xFF7F00; // Orange
		else if (i < (100 / 7 * 3))
			color = 0xFFFF00; // Yellow
		else if (i < (100 / 7 * 4))
			color = 0x00FF00; // Green
		else if (i < (100 / 7 * 5))
			color = 0x0000FF; // Blue
		else if (i < (100 / 7 * 6))
			color = 0x4B0082; // Indigo
		else
			color = 0x8B00FF; // Violet
		for (j = 0; j < 100; j++)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
		}
	}
}
