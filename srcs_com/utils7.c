/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:56:46 by lmaujean          #+#    #+#             */
/*   Updated: 2022/04/04 23:56:47 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1 << 10);
	}
	return (0);
}

int	get_size_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	size = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			size++;
		if (i == 0)
			data->x = j;
	}
	data->y = i;
	return (data->y * data->x);
}

void	int_map(t_data *data, int *k, int i, int j)
{		
	if (data->total_map[i][j] == 'N')
		data->player_direction = 'N';
	if (data->total_map[i][j] == 'S')
		data->player_direction = 'S';
	if (data->total_map[i][j] == 'E')
		data->player_direction = 'E';
	if (data->total_map[i][j] == 'W')
		data->player_direction = 'W';
	*k += 1;
	data->int_map[*k] = 2;
}

void	get_int_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	data->int_map = malloc(get_size_map(data->total_map, data) * sizeof(int));
	while (data->total_map[++i])
	{
		j = -1;
		while (data->total_map[i][++j])
		{
			if (data->total_map[i][j] == 'N' || data->total_map[i][j] == 'E'
				|| data->total_map[i][j] == 'W' || data->total_map[i][j] == 'S')
				int_map(data, &k, i, j);
			else if (ft_isdigit(data->total_map[i][j]) == 0)
				data->int_map[++k] = -1;
			else
				data->int_map[++k] = data->total_map[i][j] - 48;
		}
	}
	while (++k != (data->x) * (data->y))
		data->int_map[k] = -1;
}

t_data	*parsing(int ac, char **av)
{
	t_data	*map;
	int		fd;

	map = malloc(sizeof(t_data));
	init_struct(map);
	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_valid_file(av[1]);
		ft_get_param(fd, av[1], map);
		ft_check_carac_map(map);
		ft_check_first_line(map);
		get_int_map(map);
	}
	return (map);
}
