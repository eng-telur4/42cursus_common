/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:31:28 by rpinto-r          #+#    #+#             */
/*   Updated: 2025/02/09 20:54:38 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_params(t_rt *rt, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0)
		return (parse_resolution(rt, line));
	if (ft_strncmp(line, "A", 1) == 0)
		return (parse_ambient(rt, line));
	if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(rt, line, 0));
	if (ft_strncmp(line, "L", 1) == 0)
		return (parse_light(rt, line));
	if (ft_strncmp(line, "sp", 2) == 0)
		return (parse_shape(rt, line, id_sphere, NB_PARAMS_SPHERE));
	if (ft_strncmp(line, "pl", 2) == 0)
		return (parse_shape(rt, line, id_plane, NB_PARAMS_PLANE));
	if (ft_strncmp(line, "cy", 2) == 0)
		return (parse_shape(rt, line, id_cylinder, NB_PARAMS_CYLINDER));
	if (ft_strncmp(line, "co", 2) == 0)
		return (parse_shape(rt, line, id_cone, NB_PARAMS_CONE));
	if (ft_strncmp(line, "tr", 2) == 0)
		return (parse_shape(rt, line, id_triangle, NB_PARAMS_TRIANGLE));
	if (ft_strncmp(line, "to", 2) == 0)
		return (parse_shape(rt, line, id_torus, NB_PARAMS_TORUS));
	return (0);
}

int	parse_extra_params(t_rt *rt, t_obj *obj, char **params, int i)
{
	while (params && params[++i])
	{
		rt->pnum = i;
		if (ft_strncmp(params[i], "spc", 3) == 0 && parse_specular(params[i]
				+ 4, obj))
			return (show_parsing_error(rt, params, ERR_INVALID_SPEC_PARAMS));
		if (ft_strncmp(params[i], "mir", 3) == 0 && parse_float(params[i] + 4,
				&obj->mirror))
			return (show_parsing_error(rt, params, ERR_NOT_A_FLOAT));
		if (ft_strncmp(params[i], "ref", 3) == 0 && parse_float(params[i] + 4,
				&obj->refract))
			return (show_parsing_error(rt, params, ERR_NOT_A_FLOAT));
		if (ft_strncmp(params[i], "pat", 3) == 0 && parse_pattern(params[i] + 4,
				obj))
			return (show_parsing_error(rt, params, ERR_INVALID_PATTERN_PARAMS));
		if (ft_strncmp(params[i], "bum", 3) == 0 && parse_bump(params[i] + 4,
				obj))
			return (show_parsing_error(rt, params, ERR_INVALID_BUMP_PARAMS));
		if (ft_strncmp(params[i], "txm", 3) == 0 && parse_texture(params[i] + 4,
				obj))
			return (show_parsing_error(rt, params, ERR_INVALID_TEXTURE_PARAMS));
		if (ft_strncmp(params[i], "alp", 3) == 0 && parse_float(params[i] + 4,
				&obj->alpha))
			return (show_parsing_error(rt, params, ERR_NOT_A_FLOAT));
	}
	return (0);
}

int	parse_shape(t_rt *rt, char *line, t_obj_id id, int nb_params)
{
	t_obj	*obj;
	char	**params;

	params = ft_split(line, ' ');
	if (array_length(params) < nb_params)
		return (show_parsing_error(rt, params, ERR_INVALID_NB_PARAMS));
	obj = create_object(rt, id);
	if (id == id_plane && parse_plane(rt, params, obj))
		return (1);
	if (id == id_sphere && parse_sphere(rt, params, obj))
		return (1);
	if (id == id_cylinder && parse_cylinder(rt, params, obj))
		return (1);
	if (id == id_cone && parse_cone(rt, params, obj))
		return (1);
	if (id == id_triangle && parse_triangle(rt, params, obj))
		return (1);
	if (array_length(params) > nb_params && parse_extra_params(rt, obj, params,
			nb_params - 1))
		return (1);
	free_array(params);
	return (0);
}
