/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:47:20 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 13:05:02 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "struct.h"
# include "keycode_qwerty.h"
# define NBR_IMG 5

int		main(int argc, char **argv);
int		cast_img(t_map map);
int		keycode_management(int keycode, t_map *map);
void	keycode_management_2(int keycode, t_map *map);
void	keycode_up(t_map *map);
void	keycode_down(t_map *map);
void	keycode_left(t_map *map);
void	keycode_right(t_map *map);
void	keycode_rotate_left(t_map *map);
void	keycode_rotate_right(t_map *map);
void	keycode_esc(t_map *map);
void	free_split(char **cpy_argv);
int		ciao(t_map *map);
void	error_san(int error, char *error_msg);
char	**build_map(char **argv, t_map *n);
void	check_bit_by_bit(char **tmp, t_map *n);
void	check_requirements(char *line_map, int y, t_map *n);
void	check_surrounding_walls_part1(char char_map, int x, int y, t_map *n);
void	check_surrounding_walls_part2(char char_map, int x, int y, t_map *n);
int		elements_signal(char char_map, int x, int y, t_map *n);
char	**malloc_map_arr(char **argv, t_map *n);
char	**malloc_and_create_map_string(char **argv, t_map *n);
void	init_struct(t_map *n);
int		determine_angle(char char_map);
void	print_map(t_map *map);
void	print_moves(t_map *map);
void	print(t_map *map);
void	graphics_help(t_map *map);
void	p1_vertical_ray_casting(t_map *map, float angle);
void	p2_vertical_ray_casting(t_map *map, \
		float increment_x, float increment_y);
void	p1_horizontal_ray_casting(t_map *map, float angle);
void	p2_horizontal_ray_casting(t_map *map, float increment_x, \
		float increment_y);
void	print_rays(t_map *map, float angle, int i);
void	forbidden_angle_horizontal(t_map *map, float angle);
void	forbidden_angle_vertical(t_map *map, float angle);
void	tiles(t_map *map, int x, int y);
int		color(t_map *map, int x, int y);	
void	pixel(t_map *map, int x, int y, int color);
void	end(char **str, int error, char *error_msg);
int		*load_img(t_map *map, char *path);
void	ft_load_img(t_map *map);

#endif
