/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:56:26 by bgoncalv          #+#    #+#             */
/*   Updated: 2025/02/09 20:55:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	reflect_vect(t_vect v, t_vect n)
{
	t_vect	dst;

	dst = vect_mul(n, 2 * dot_prod(v, n));
	dst = vect_sub(dst, v);
	return (dst);
}

t_vect	refract_vect(t_vect v, t_vect n, float eta)
{
	float	c1;
	float	c2;
	t_vect	dst;

	c1 = dot_prod(v, n);
	c2 = sqrt(1 - eta * eta * (1 - c1 * c1));
	dst = vect_mul(n, eta * c1 - c2);
	dst = vect_add(dst, vect_mul(v, eta));
	normalize(&dst);
	return (dst);
}
