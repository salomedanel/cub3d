/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/23 13:33:43 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp("1", map->map[i], 1) == 0)
			return (i);
		else if (ft_strncmp(" ", map->map[i], 1) == 0)
			return (i);
		else if (ft_strncmp("0", map->map[i], 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

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

int	parse_texture_path(t_map *map)
{
	if (access(map->no, F_OK) != 0 || access(map->so, F_OK) != 0
		|| access(map->we, F_OK) != 0 || access(map->ea, F_OK) != 0)
		return (printf("Wrong texture path\n"), -1);
	else
		printf("Texture path OK\n");
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
	printf("Floor and ceiling OK\n");
	freetab(map->f);
	freetab(map->c);
	return (0);
}
