/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/23 15:52:56 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture(t_map *map)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
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
			return (printf("%s\n", ERR_PLACE), -1);
	}
	if (counter != 6)
		return (printf("%s\n", ERR_TXT), -1);
	return (0);
}

int	parse_fc(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
	{
		if (ft_strncmp("F", map->map[i], 1) == 0)
		{
			if (contains_comma(map->map[i]) != 2)
				return (printf("%s\n", ERR_FC), -1);
			map->f = ft_split(map->map[i], ',');
			if (map->f[0] == NULL || map->f[1] == NULL || map->f[2] == NULL)
				return (printf("%s\n", ERR_FC), -1);
			map->colors[0] = ft_unsigned_atoi(map->f[0] + 2);
			map->colors[1] = ft_unsigned_atoi(map->f[1]);
			map->colors[2] = ft_unsigned_atoi(map->f[2]);
		}
		else if (ft_strncmp("C", map->map[i], 1) == 0)
		{
			if (contains_comma(map->map[i]) != 2)
				return (printf("%s\n", ERR_FC), -1);
			map->c = ft_split(map->map[i], ',');
			if (map->c[0] == NULL || map->c[1] == NULL || map->c[2] == NULL)
				return (printf("%s\n", ERR_FC), -1);
			map->colors[3] = ft_unsigned_atoi(map->c[0] + 2);
			map->colors[4] = ft_unsigned_atoi(map->c[1]);
			map->colors[5] = ft_unsigned_atoi(map->c[2]);
		}
	}
	i = 0;
	while (i < 6)
	{
		if (map->colors[i] > 255)
			return (printf("%s\n", ERR_FC), -1);
		i++;
	}
	freetab(map->f);
	freetab(map->c);
	return (0);
}

int	check_emptymap(t_map *map)
{
	int	i;

	i = map->startline - 1;
	if (map->startline == -1)
		return (printf("Error\nNo map\n"), -1);
	while (map->map[++i])
	{
		if (map->map[i][0] == '\n')
			return (printf("Error\nEmpty line in map - line %d\n", i), -1);
	}
	return (0);
}

int	check_mapchar(t_map *map)
{
	int		i;
	int		j;

	i = map->startline;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != 'N' || map->map[i][j] != 'S'
				|| map->map[i][j] != 'E' || map->map[i][j] != 'W'
				|| map->map[i][j] != '0' || map->map[i][j] != '1')
				return (printf("Error\nInvalid character in map\n"), -1);
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

	i = map->startline;
	counter = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] != 'S'
				|| map->map[i][j] != 'E' || map->map[i][j] != 'W')
			{
				ppos.x = i;
				ppos.y = j;
				ppos.dir = map->map[i][j];
				counter++;
			}
			j++;
		}
		i++;
	}
	if (counter > 1)
		return (printf("Error\nMultiple player positions\n"), -1);
	return (0);
}

