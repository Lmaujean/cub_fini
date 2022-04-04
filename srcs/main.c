/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:43 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 13:15:13 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>

void	draw_square(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int	i;
	int	j;

	i = a.x;
	j = a.y;
	while (i < b.x)
	{
		j = a.y;
		while (j < b.y)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->s_height)
	{
		j = 0;
		while (j < data->s_width)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_map_2d(t_data *data)
{
	int	xo;
	int	yo;
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			xo = x * MAPTILE / 4;
			yo = y * MAPTILE / 4;
			if (data->int_map[y * data->x + x] == 1)
				draw_square(data, new_vec2(xo + 1, yo + 1),
					new_vec2(xo + MAPTILE / 4 - 1, yo + MAPTILE / 4 - 1),
					0x00000000);
			else if (data->int_map[y * data->x + x] == 0)
				draw_square(data, new_vec2(xo + 1, yo + 1),
					new_vec2(xo + MAPTILE / 4 - 1, yo + MAPTILE / 4 - 1),
					0x00FFFFFF);
			x++;
		}
		y++;
	}
}

int	close_w(t_data *parsed)
{
	free_exit(parsed, 0, NULL);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	*map;

	map = parsing(ac, av);
	map_get_ply_pos_fix(map);
	init_game(map);
	map->tex_n = load_image(map, map->text.no);
	map->tex_s = load_image(map, map->text.so);
	map->tex_e = load_image(map, map->text.ea);
	map->tex_w = load_image(map, map->text.we);
	mlx_hook((*map).win, 2, 1L << 0, (void *)key_handler, map);
	mlx_hook(map->win, 17, 0, close_w, map);
	mlx_loop_hook((*map).mlx, render, map);
	mlx_loop((*map).mlx);
}
