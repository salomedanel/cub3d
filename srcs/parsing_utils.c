/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:44:24 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/23 15:41:06 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	contains_comma(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i] != '\n')
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

int	ft_unsigned_atoi(t_map *map, const char *nptr, int malloc)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (nptr[i] && nptr[i] == '-')
	{
		if (malloc == 1)
			freetab(map->f);
		if (malloc == 2)
		{
			freetab(map->f);
			freetab(map->c);
		}
		exit_parserror(map, "Error\nInvalid color id\n");
	}
	while (nptr[i])
	{
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '\n')
		{
			if (malloc == 1)
				freetab(map->f);
			if (malloc == 2)
			{
				freetab(map->f);
				freetab(map->c);
			}
			exit_parserror(map, "Error\nInvalid color id\n");
		}
		i++;
	}
	i = -1;
	while (nptr[++i] >= '0' && nptr[i] <= '9')
		res = res * 10 + (nptr[i] - '0');
	return (res);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}
