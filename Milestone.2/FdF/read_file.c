#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_point3_3d
{
	int		x;
	int		y;
	int		z;
}			t_point_3d;

typedef struct s_point2_2d
{
	int		x;
	int		y;
}			t_point_2d;

#define ISO_ANGLE (M_PI / 6) // 30度をラジアンに変換

// 等角投影を適用
t_point_2d	isometric_projection(t_point_3d point)
{
	t_point_2d	projection;

	projection.x = (int)(point.x * cos(ISO_ANGLE) - point.y * cos(ISO_ANGLE));
	projection.y = (int)(point.x * sin(ISO_ANGLE) + point.y * sin(ISO_ANGLE)
			- point.z);
	return (projection);
}

int	main(void)
{
	char	*filename;
	int		fd;
	char	*line;
	char	**point_str;
	int		line_count;
	int		point_count;
	int		point_index;
	int		total_points;

	t_point_3d *points;    // 3D座標のリスト（動的配列）
	t_point_2d *points_2d; // 2D座標のリスト（動的配列）
	filename = "test_maps/42.fdf";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Could not open file\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	line_count = 0;
	total_points = 0;
	points = NULL;
	// 3Dデータの読み込み
	while ((line = get_next_line(fd)))
	{
		point_str = ft_split(line, ' ');
		point_count = 0;
		while (point_str[point_count])
			point_count++;
		// メモリ拡張
		points = realloc(points, (total_points + point_count)
				* sizeof(t_point_3d));
		if (!points)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
			close(fd);
			return (EXIT_FAILURE);
		}
		// 3Dデータの格納
		point_index = 0;
		while (point_str[point_index])
		{
			points[total_points + point_index].x = point_index;
			points[total_points + point_index].y = line_count;
			points[total_points
				+ point_index].z = ft_atoi(point_str[point_index]);
			free(point_str[point_index]); // メモリ解放
			point_index++;
		}
		free(point_str);
		total_points += point_count;
		line_count++;
		free(line);
	}
	close(fd);
	// 2D配列のメモリ確保
	points_2d = malloc(total_points * sizeof(t_point_2d));
	if (!points_2d)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
		free(points);
		return (EXIT_FAILURE);
	}
	// 3D -> 2D の変換
	for (int i = 0; i < total_points; i++)
		points_2d[i] = isometric_projection(points[i]);
	// 2D座標の出力
	for (int i = 0; i < total_points; i++)
		ft_printf("2D Point[%d]: x=%d, y=%d\n", i, points_2d[i].x,
			points_2d[i].y);
	// メモリ解放
	free(points);
	free(points_2d);
	return (EXIT_SUCCESS);
}
