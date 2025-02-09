/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 05:02:55 by brunodeoliv       #+#    #+#             */
/*   Updated: 2025/02/09 20:55:48 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_timediff(void)
{
	static struct timeval	old_t = {0};
	struct timeval			t;
	float					sec;

	gettimeofday(&t, NULL);
	sec = (float)(t.tv_sec - old_t.tv_sec) + ((float)(t.tv_usec - old_t.tv_usec)
			/ 1000000);
	old_t = t;
	return (sec);
}
