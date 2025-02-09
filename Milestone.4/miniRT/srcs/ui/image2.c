/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:13:17 by bgoncalv          #+#    #+#             */
/*   Updated: 2025/02/09 20:55:19 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	anti_aliasing(t_rt *rt, float x, float y)
{
	t_color	c[9];
	int		i;
	int		j;
	t_rays	r;

	y -= 0.33;
	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		x -= 0.99;
		while (j < 3)
		{
			build_camray(rt, &r.prime_ray, x, y);
			c[i * 3 + j] = raytrace(rt, &r, MAX_REFLECT);
			x += 0.33;
			j++;
		}
		y += 0.33;
		i++;
	}
	return (big_mix(c));
}
