/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:56:43 by lmaujean          #+#    #+#             */
/*   Updated: 2022/04/04 22:56:44 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

int	t_color_to_int(t_color col)
{
	return (create_trgb(0, col.r, col.g, col.b));
}

float	dist_2d(float x0, float y0, float x1, float y1)
{
	return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}

t_vec2	new_vec2(float x, float y)
{
	t_vec2	out;

	out.x = x;
	out.y = y;
	return (out);
}

void	fix_angle(float *a)
{
	if (*a < 0)
		*a += 2 * PI;
	if (*a > 2 * PI)
		*a -= 2 * PI;
}
