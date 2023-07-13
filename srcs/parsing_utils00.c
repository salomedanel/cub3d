/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:44:24 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/13 17:32:49 by tmichel-         ###   ########.fr       */
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

void	invalid_atoi(t_map *map, int malloc)
{
	if (malloc == 1)
		freetab(map->f);
	if (malloc == 2)
	{
		freetab(map->f);
		freetab(map->c);
	}
	exit_parserror(map, "Error\nInvalid color id\n");
	return ;
}

int    ft_unsigned_atoi(t_map *map, const char *nptr, int malloc)
{
    int    res;
    int    i;

    res = 0;
    i = 0;
    if (nptr[i] && nptr[i] == '-')
        invalid_atoi(map, malloc);
    while (nptr[i] == ' ')
        i++;
    while (nptr[i])
    {
        if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '\n')
            invalid_atoi(map, malloc);
        i++;
    }
    i = -1;
    while (nptr[++i] >= '0' && nptr[i] <= '9')
        res = res * 10 + (nptr[i] - '0');
    while (nptr[i] == ' ')
        i++;
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

int	len_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = map->startline;
	len = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (len < j)
			len = j;
		i++;
	}
	return (len);
}
