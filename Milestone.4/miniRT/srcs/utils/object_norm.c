/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:36:43 by bgoncalv          #+#    #+#             */
/*   Updated: 2025/02/09 20:55:41 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	triangle_norm(t_rt *rt, t_triangle *t)
{
	t_vect	v;
	t_vect	tmp;

	t->edge[0] = vect_sub(t->c[0], t->c[1]);
	t->edge[1] = vect_sub(t->c[1], t->c[2]);
	t->edge[2] = vect_sub(t->c[2], t->c[0]);
	t->n = cross_prod(t->edge[0], t->edge[1]);
	t->area2 = vectlen(t->n);
	normalize(&t->n);
	v = vect_sub(rt->camera.orient, t->c[0]);
	if (dot_prod(v, t->n) > 0)
	{
		tmp = t->c[1];
		t->c[1] = t->c[2];
		t->c[2] = tmp;
		triangle_norm(rt, t);
	}
}

void	cone_norm(t_cone *c)
{
	normalize(&c->orient);
	c->cos2 = pow(cos(c->angle), 2);
	c->c1 = vect_mul(c->orient, c->h);
	c->c1 = vect_add(c->c1, c->coords);
	c->c2 = vect_mul(c->orient, -c->h2);
	c->c2 = vect_add(c->c2, c->coords);
	c->r1 = tan(c->angle) * c->h;
	c->r2 = tan(c->angle) * c->h2;
}

void	cylinder_norm(t_cylinder *cy)
{
	normalize(&cy->orient);
	cy->r2 = cy->diameter * cy->diameter * 0.25;
	cy->delta_p = vect_mul(cy->orient, cy->height);
	cy->p1 = vect_mul(cy->orient, -0.5 * cy->height);
	cy->p1 = vect_add(cy->p1, cy->coords);
	cy->p2 = vect_mul(cy->orient, 0.5 * cy->height);
	cy->p2 = vect_add(cy->p2, cy->coords);
}

void	handle_img(t_rt *rt, t_obj *obj)
{
	if (obj->has_texture && !obj->texture.img)
	{
		obj->texture.img = mlx_xpm_file_to_image(rt->mlx, obj->texture.path,
				&obj->texture.width, &obj->texture.height);
		if (!obj->texture.img)
			obj->has_texture = FALSE;
		else
			obj->texture.addr = mlx_get_data_addr(obj->texture.img,
					&obj->texture.bits_per_pixel, &obj->texture.line_length,
					&obj->texture.endian);
	}
	if (obj->has_bump && !obj->bump.img)
	{
		obj->bump.img = mlx_xpm_file_to_image(rt->mlx, obj->bump.path,
				&obj->bump.width, &obj->bump.height);
		if (!obj->bump.img)
			obj->has_bump = FALSE;
		else
			obj->bump.addr = mlx_get_data_addr(obj->bump.img,
					&obj->bump.bits_per_pixel, &obj->bump.line_length,
					&obj->bump.endian);
	}
}

void	object_norm(t_rt *rt)
{
	t_obj		*objs;
	t_camera	*cam;

	cam = &rt->camera;
	cam->scale = tan(cam->fov / 2 * M_PI / 180);
	rt->aspectratio = (float)rt->width / rt->height;
	rt->img.addr_incr = rt->img.bits_per_pixel / 8;
	rt->bg_color = rgb2color(0x424242);
	lookat(rt);
	objs = rt->objs;
	while (objs)
	{
		handle_img(rt, objs);
		if (objs->id == id_sphere)
			objs->object.sphere.r2 = pow(objs->object.sphere.diameter / 2, 2);
		if (objs->id == id_cone)
			cone_norm(&objs->object.cone);
		if (objs->id == id_triangle)
			triangle_norm(rt, &objs->object.triangle);
		if (objs->id == id_cylinder)
			cylinder_norm(&objs->object.cylinder);
		set_patternref(rt, objs);
		objs = objs->next;
	}
}
