/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:14:59 by lmaujean          #+#    #+#             */
/*   Updated: 2022/04/05 13:15:00 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

void	add_in_text3(t_data *game, char *str)
{
	char	**split;
	char	*line;
	char	**tmp;

	tmp = NULL;
	split = ft_split(str, ' ');
	line = ft_strtrim(split[0], " \t");
	if (!ft_strncmp(line, "C", 2) && game->text.c == NULL)
	{
		game->text.c = ft_strdup(split[1]);
		if (game->text.c != NULL)
			tmp = ft_split(game->text.c, ',');
		else
			ft_error(9, game);
		if (tmp[0])
			game->ceiling_color.r = ft_atoi(tmp[0]);
		if (tmp[1])
			game->ceiling_color.g = ft_atoi(tmp[1]);
		if (tmp[2])
			game->ceiling_color.b = ft_atoi(tmp[2]);
		ft_freedouble(tmp);
	}
	ft_freedouble(split);
	free(line);
}

void	add_in_text2(t_data *game, char *str)
{
	char	**split;
	char	*line;
	char	**tmp;

	tmp = NULL;
	split = ft_split(str, ' ');
	line = ft_strtrim(split[0], " \t");
	if (!ft_strncmp(line, "F", 2) && game->text.f == NULL)
	{
		game->text.f = ft_strdup(split[1]);
		if (game->text.f != NULL)
			tmp = ft_split(game->text.f, ',');
		else
			ft_error(9, game);
		if (tmp[0])
			game->floor_color.r = ft_atoi(tmp[0]);
		if (tmp[1])
			game->floor_color.g = ft_atoi(tmp[1]);
		if (tmp[2])
			game->floor_color.b = ft_atoi(tmp[2]);
		ft_freedouble(tmp);
	}
	add_in_text3(game, str);
	ft_freedouble(split);
	free(line);
}

int	ft_check_ext2(const char *file, const char *ext)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (file[len_file - 1] != ext[len_ext - 1])
		{
			printf("Error\nFile Not .xpm\n");
			exit(EXIT_FAILURE);
		}
		len_file--;
		len_ext--;
	}
	return (1);
}
