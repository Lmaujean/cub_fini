/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:26 by juan              #+#    #+#             */
/*   Updated: 2022/03/15 21:30:22 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "keycode_qwerty.h"
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# elif __APPLE__
#  include <mlx.h>
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int			x;
	int			y;
	float		a;
	float		dx;
	float		dy;
	float		disth;
	float		hx;
	float		hy;
	float		distv;
	float		vx;
	float		vy;
}				t_player;

/******* STRUCTURE TEXTURE *******/

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_texture;

/******* STRUCTURE GLOBAL DU JEU *******/

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			s_width;
	int			s_height;
	int			*tex_n;
	int			*tex_s;
	int			*tex_e;
	int			*tex_w;
	int			img_xpm_width;
	int			img_xpm_height;
	t_color		floor_color;
	t_color		ceiling_color;
	int			*int_map;
	int			x;
	int			y;
	t_player	ply;
	int			ply_x;
	int			ply_y;
	char		player_direction;
	char		*texture[6];
	char		**total_map;
	t_texture	text;
}					t_data;

typedef struct s_param
{
	int		exist;
	char	*value;
}	t_param;

typedef struct s_check
{
	t_param		no;
	t_param		so;
	t_param		we;
	t_param		ea;
	t_param		f;
	t_param		c;
}	t_check;

/******* RAYCAST *******/

void			compute_draw_ray_tex(t_data *data, int *tab, float *tabf);
void			compute_draw_ray_init_line_arg(t_data *data, \
				int *tab, float *tabf);
void			compute_draw_ray(t_data *data);
void			compute_draw_ray_vertical(t_data *data, int *tab, float *tabf);
void			compute_draw_ray_vertical2(t_data *data, int *tab, float *tabf);
void			compute_draw_ray_horizontal(t_data *data, int *tab, \
											float *tabf);
void			compute_draw_ray_horizontal2(t_data *data, int *tab, \
											float *tabf);
void			compute_draw_ray_dist_init_line(t_data *data, int *tab, \
											float *tabf);
int				t_color_to_int(t_color col);
float			dist_2d(float x0, float y0, float x1, float y1);
t_vec2			new_vec2(float x, float y);
void			fix_angle(float *a);
void			draw2d(t_data *data);
int				render(t_data *data);
float			p2f(void);
float			p3f(void);
void			key_a_handle(int keycode, t_data *data, int *tab);
void			key_d_handle(int keycode, t_data *data, int *tab);
void			key_ws_handle(int keycode, t_data *data, int *tab);
void			key_left_right_esc_handle(int keycode, t_data *data);
void			key_handler(int keycode, t_data *data);
int				create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				*load_image_malloc(t_data *data, int *tab, int *xpm_data);
int				*load_image(t_data *data, char *path);
void			map_player_pos(t_data *parsed);
void			init_game(t_data *parsed);
void			init_player_direction(t_data *parsed);
void			free_exit2(t_data *parsed, char *print_msg_newline);
void			free_exit(t_data *parsed, int code, char *print_msg_newline);
void			draw_square(t_data *data, t_vec2 a, t_vec2 b, int color);
void			draw_background(t_data *data, int color);
void			draw_map_2d(t_data *data);
int				close_w(t_data *parsed);

/******* GNL *******/

char			*ft_strdup(const char *src);
char			*ft_substr(char *s, int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_save(char **save);
int				get_line(char **line, char **save);
int				return_l(char **line, char **save, int byte_lu);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);

/******* PARSING *******/

int				ft_valid_fd(char *str, int ac);
void			ft_valid_file(char *str);
char			**ft_get_file(int fd, const char *str, int k);
void			check_text(int fd, t_data *game);
void			ft_get_param(int fd, char *str, t_data *game);
int				ft_check_param_file(char *str);
int				ft_comp_str(char *str, char *str2);
void			ft_one_position(t_data *game		);
void			ft_check_nbr_carac(t_data *game);
void			ft_check_carac_map(t_data *game);
void			ft_check_first_line(t_data *game);
void			ft_check_last_line(t_data *game);
void			ft_check_first_carac(t_data *game);
void			ft_check_rgb_floor(t_data *game);
void			add_in_text(t_data *game, char *str);
void			ft_check_int_f(t_data *game);
void			valid_path_texture(char *str, t_data *game);
char			**ft_get_map(int fd, const char *str, t_data *game, int i);
void			check_next_line(t_data *g, int i, int j);
void			add_in_text3(t_data *game, char *str);
void			add_in_text2(t_data *game, char *str);

/******* UTILS *******/

int				ft_error(int c, t_data *game);
int				ft_strlen(const char *str);
int				ft_check_ext(const char *file, const char *ext);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
int				ft_tab_len(char **tab);
int				ft_strcomp(const char *s1, char *s2);
char			*ft_str_nospace(char *str);
int				len_str_with_space(char *str);
void			init_check(t_check *check);
char			*ft_strtrim(char *s1, char *set);
void			ft_freedouble(char **ptr);
void			init_carac(t_data *game);
int				ft_count_char(char *str, char c);
void			ft_free_texture(t_texture *text);
int				ft_strisdigit(char *str);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t count, size_t size);
int				count_line(int fd, char *str);
void			ft_save_text(t_data *game, char **file);
void			ft_freeallchar(t_data *game);
void			init_struc(t_data *game);
void			ft_free_game(t_data *game);
void			ft_player(t_data *game, int i, int j);
int				empty(char *str);
void			init_raycast(t_data *game);
void			print_doublechar(char **tab);
int				check_last_line_nul(t_data *map);
int				ft_first_line_of_map(char *str);
void			init_struct(t_data *map);
t_data			*pars_cub(int ac, char **av);
void			get_int_map(t_data *data);
void			int_map(t_data *data, int *k, int i, int j);
int				get_size_map(char **map, t_data *data);
char			*get_file(char *path);
char			**parse_file(char *path);
int				ft_check_ext2(const char *file, const char *ext);

#endif