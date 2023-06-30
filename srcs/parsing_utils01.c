/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:12 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/30 14:06:07 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_colors(t_map *map, int fc_malloc, char c)
{
	if (c == 'f')
	{
		map->colors[0] = ft_unsigned_atoi(map, map->f[0] + 2, fc_malloc);
		map->colors[1] = ft_unsigned_atoi(map, map->f[1], fc_malloc);
		map->colors[2] = ft_unsigned_atoi(map, map->f[2], fc_malloc);
	}
	else if (c == 'c')
	{
		map->colors[3] = ft_unsigned_atoi(map, map->c[0] + 2, fc_malloc);
		map->colors[4] = ft_unsigned_atoi(map, map->c[1], fc_malloc);
		map->colors[5] = ft_unsigned_atoi(map, map->c[2], fc_malloc);
	}
	return ;
}

void	check_colors_value(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map->colors[i] > 255)
		{
			freetab(map->f);
			freetab(map->c);
			exit_parserror(map, ERR_FC);
			return ;
		}
		i++;
	}
	freetab(map->f);
	freetab(map->c);
	return ;
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
