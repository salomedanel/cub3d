/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/20 12:04:49 by sdanel           ###   ########.fr       */
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
	int	start;

	i = -1;
	counter = 0;
	start = start_map(map);
	while (map->map[++i])
	{
		if (ft_strncmp("NO", map->map[i], 2) == 0)
			counter++;
		else if (ft_strncmp("SO", map->map[i], 2) == 0)
			counter++;
		else if (ft_strncmp("WE", map->map[i], 2) == 0)
			counter++;
		else if (ft_strncmp("EA", map->map[i], 2) == 0)
			counter++;
		else if (ft_strncmp("F", map->map[i], 1) == 0)
			counter++;
		else if (ft_strncmp("C", map->map[i], 1) == 0)
			counter++;
		if (i > start && counter < 6)
			return (printf("%s\n", ERR_TXT), -1);
	}
	return (-1);
}
