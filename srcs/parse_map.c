/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/26 13:55:57 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture(t_map *map)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	init_data(map);
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

int	parse_fc(t_map *map)
{
	int	i;
	int	fc_malloc;

	i = -1;
	fc_malloc = 0;
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
			map->colors[0] = ft_unsigned_atoi(map, map->f[0] + 2, fc_malloc);
			map->colors[1] = ft_unsigned_atoi(map, map->f[1], fc_malloc);
			map->colors[2] = ft_unsigned_atoi(map, map->f[2], fc_malloc);
		}
		else if (ft_strncmp("C", map->map[i], 1) == 0)
		{
			if (contains_comma(map->map[i]) != 2)
				return (freetab(map->f), exit_parserror(map, ERR_FC));
			map->c = ft_split(map->map[i], ',');
			if (map->c[0] == NULL || map->c[1] == NULL || map->c[2] == NULL)
				return (exit_parserror(map, ERR_FC));
			fc_malloc = 2;
			map->colors[3] = ft_unsigned_atoi(map, map->c[0] + 2, fc_malloc);
			map->colors[4] = ft_unsigned_atoi(map, map->c[1], fc_malloc);
			map->colors[5] = ft_unsigned_atoi(map, map->c[2], fc_malloc);
		}
	}
	i = 0;
	while (i < 6)
	{
		if (map->colors[i] > 255)
			return (freetab(map->f), freetab(map->c), exit_parserror(map, ERR_FC));
		i++;
	}
	freetab(map->f);
	freetab(map->c);
	return (0);
}

int	check_emptyline(t_map *map)
{
	int	i;

	i = map->startline - 1;
	if (map->startline == -1)
		return (exit_parserror(map, "Error\nNo map\n"));
	while (map->map[++i])
	{
		if (map->map[i][0] == '\n')
			return (exit_parserror(map, "Error\nEmpty line in map\n"));
	}
	return (0);
}

int	check_mapchar(t_map *map)
{
	int		i;
	int		j;

	//i = map->startline;
	i = 0;
	while (map->f_map[i])
	{
		j = 0;
		while (map->f_map[i][j])
		{
			if (map->f_map[i][j] != 'N' && map->f_map[i][j] != 'S'
				&& map->f_map[i][j] != 'E' && map->f_map[i][j] != 'W'
				&& map->f_map[i][j] != '0' && map->f_map[i][j] != '1' && map->f_map[i][j] != '\n')
				return (exit_parserror2(map, "Error\nInvalid character in map\n"));
			j++;
		}
		i++;
	}
	return (0);
}

int	get_playerpos(t_map *map)
{
	int		i;
	int		j;
	int		counter;
	t_pos	ppos;

	i = 0;
	counter = 0;
	ppos.x = 0;
	ppos.y = 0;
	ppos.dir = 0;
	while (map->f_map[i])
	{
		j = 0;
		while (map->f_map[i][j] != '\n')
		{
			if (map->f_map[i][j] == 'N' || map->f_map[i][j] == 'S'
				|| map->f_map[i][j] == 'E' || map->f_map[i][j] == 'W')
			{
				ppos.x = i - map->startline;
				ppos.y = j;
				ppos.dir = map->f_map[i][j];
				counter++;
			}
			j++;
		}
		i++;
	}
	printf("x = %d | y = %d | dir = %c\n", ppos.x, ppos.y, ppos.dir);
	if (counter == 0)
		return (exit_parserror2(map, "Error\nNo player\n"));
	if (counter > 1)
		return (exit_parserror2(map, "Error\nMultiple player positions\n"));
	return (0);
}

int	map_outline(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->sizeline = len_map(map);
	printf("i = %d\n", i);
	while (map->f_map[i])
	{
		if (map->f_map[i][0] != '1' && map->f_map[i][map->sizeline] != '1' && map->f_map[i][0] != '\n' && map->f_map[i][map->sizeline] != '\n')
		{
			printf("Ici - i = %d | sizeline = %d\n", i, map->sizeline);
			return (exit_parserror2(map, "Error\nInvalid map\n"));
		}
		i++;
	}
	j = 0;
	while (map->f_map[0][j] && j < map->sizeline)
	{
		if (map->f_map[0][j] != '1' || map->f_map[0][j] != '\n' || map->f_map[0][j] != '\0')
		{
			printf("Ici1 - startline = %d | j = %d\n", map->startline, j);
			return (exit_parserror2(map, "Error\nInvalid map\n"));
		}
		j++;
	}
	j = 0;
	while (map->f_map[map->nbline][j])
	{
		if (map->map[map->nbline][j] != '1')
		{
			printf("Ici2 - nbline = %d | j = %d\n", map->nbline, j);
			return (exit_parserror2(map, "Error\nInvalid map\n"));
		}
		j++;
	}
	return (printf("Map ok\n"));
}
