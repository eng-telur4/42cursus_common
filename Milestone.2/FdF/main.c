#include <math.h>
#include <stdio.h>

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

t_point_2d	isometric_projection(t_point_3d point)
{
	t_point_2d	projection;

	projection.x = point.x * cos(30) - point.y * cos(30);
	projection.y = point.x * sin(30) + point.y * sin(30) - point.z;
	return (projection);
}

int	main(void)
{
	t_point_3d	cube[8] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
			{-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};
	t_point_2d	projection;

	printf("3D to 2D Isometric Projection\n");
	for (int i = 0; i < 8; i++)
	{
		projection = isometric_projection(cube[i]);
		printf("3D: (%d, %d, %d) -> 2D: (%d, %d)\n", cube[i].x, cube[i].y,
			cube[i].z, projection.x, projection.y);
	}
}
