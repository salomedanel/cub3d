/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/14 10:48:22 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture(t_map *map, int counter, t_rc *rc)
{
	int	i;

	i = -1;
	init_data(map, rc);
	map->startline = start_map(map);
	while (map->map[++i])
	{
		if (ft_strncmp("NO", map->map[i], 2) == 0)
			get_texture_no(map->map[i], &counter, "NO", map);
		else if (ft_strncmp("SO", map->map[i], 2) == 0)
			get_texture_so(map->map[i], &counter, "SO", map);
		else if (ft_strncmp("WE", map->map[i], 2) == 0)
			get_texture_we(map->map[i], &counter, "WE", map);
		else if (ft_strncmp("EA", map->map[i], 2) == 0)
			get_texture_ea(map->map[i], &counter, "EA", map);
		else if (ft_strncmp("F", map->map[i], 1) == 0)
			counter++;
		else if (ft_strncmp("C", map->map[i], 1) == 0)
			counter++;
		if (i == map->startline && counter != 6)
			return (exit_parserror(map, ERR_PLACE));
	}
	if (counter != 6)
		return (exit_parserror(map, ERR_PLACE));
	return (0);
}

int	parse_fc(t_map *map, int fc_malloc, int i)
{
	while (map->map[++i])
	{
		if (ft_strncmp("F", map->map[i], 1) == 0)
		{
			if (contains_comma(map->map[i]) != 2)
				return (exit_parserror(map, ERR_FC));
			map->f = ft_split(map->map[i], ',');
			if (map->f[0] == NULL || map->f[1] == NULL || map->f[2] == NULL)
				return (exit_parserror(map, ERR_FC));
			fc_malloc = 1;
			fill_colors(map, fc_malloc, 'f');
		}
		else if (ft_strncmp("C", map->map[i], 1) == 0)
		{
			if (contains_comma(map->map[i]) != 2)
				return (freetab(map->f), exit_parserror(map, ERR_FC));
			map->c = ft_split(map->map[i], ',');
			if (map->c[0] == NULL || map->c[1] == NULL || map->c[2] == NULL)
				return (exit_parserror(map, ERR_FC));
			fc_malloc = 2;
			fill_colors(map, fc_malloc, 'c');
		}
	}
	check_colors_value(map);
	return (0);
}

int	check_mapchar(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->f_map[i])
	{
		j = 0;
		while (map->f_map[i][j])
		{
			if (map->f_map[i][j] != 'N' && map->f_map[i][j] != 'S'
				&& map->f_map[i][j] != 'E' && map->f_map[i][j] != 'W'
				&& map->f_map[i][j] != '0' && map->f_map[i][j] != '1'
					&& map->f_map[i][j] != '\n')
				return (exit_parserror2(map, "Error\nInvalid char in map\n"));
			j++;
		}
		i++;
	}
	return (0);
}

int	get_playerpos(t_map *map, t_rc *rc, int counter)
{
	int		i;
	int		j;

	i = -1;
	while (map->f_map[++i])
	{
		j = -1;
		while (map->f_map[i][++j] != '\n')
		{
			if (map->f_map[i][j] == 'N' || map->f_map[i][j] == 'S'
				|| map->f_map[i][j] == 'E' || map->f_map[i][j] == 'W')
			{
				rc->posx = i + 0.5;
				rc->posy = j + 0.5;
				rc->dir = map->f_map[i][j];
				counter++;
			}
		}
	}
	if (counter == 0)
		return (exit_parserror2(map, "Error\nNo player\n"));
	if (counter > 1)
		return (exit_parserror2(map, "Error\nMultiple player positions\n"));
	return (get_orientation_full(rc), 0);
}

int	map_outline(t_map *map, int i)
{
	int	j;

	while (map->f_map[++i])
	{
		if (map->f_map[i][0] != '1' && map->f_map[i][map->length] != '1'
			&& map->f_map[i][0] != '\n' && map->f_map[i][map->length] != '\n')
			return (exit_parserror2(map, "Error\nInvalid map\n"));
	}
	j = -1;
	while (map->f_map[0][++j] && j < map->length)
	{
		if (map->f_map[0][j] != '1' && map->f_map[0][j] != '\n'
			&& map->f_map[0][j] != '\0')
			return (exit_parserror2(map, "Error\nInvalid map\n"));
	}
	j = -1;
	while (map->f_map[map->height - 1][++j])
	{
		if (map->f_map[map->height - 1][j] != '1'
			&& map->f_map[map->height - 1][j] != '\n'
			&& map->f_map[map->height - 1][j] != '\0')
			return (exit_parserror2(map, "Error\nInvalid map\n"));
	}
	return (0);
}
