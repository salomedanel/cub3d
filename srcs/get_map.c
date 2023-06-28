/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:05:55 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/26 13:51:33 by sdanel           ###   ########.fr       */
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

int	size_map(t_map *map)
{
	char	*line;

	map->nbline = 0;
	map->sizeline = 0;
	line = get_next_line(map->file, 0);
	while (line)
	{
		free(line);
		line = get_next_line(map->file, 0);
		map->nbline++;
		if (map->sizeline < ft_strlen(line))
			map->sizeline = ft_strlen(line);
	}
	free(line);
	if (map->nbline < 9)
	{
		close(map->file);
		return (printf("Error\nIncomplete file: missing info or map\n"), -1);
	}
	close(map->file);
	return (0);
}

void	cpy_map(t_map *map, char *line, int *i)
{
	int	j;

	map->map[*i] = ft_calloc(sizeof(char), (map->sizeline + 2));
	line = get_next_line(map->file, 0);
	//free(line);
	j = 0;
	while (line[j])
	{
		map->map[*i][j] = line[j];
		j++;
	}
	map->map[*i][j] = '\0';
	free(line);
	*i = *i + 1;
}

int	get_map(t_map *map, char **argv)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	map->file = open(argv[1], O_RDONLY);
	map->map = ft_calloc(sizeof(char *), (map->nbline + 1));
	if (map->map == NULL)
		return (printf("Error\nMalloc failed\n"), -1);
	while (i < map->nbline)
		cpy_map(map, line, &i);
	map->map[i] = NULL;
	close(map->file);
	return (0);
}
void	final_map(t_map *map)
{
	int	size;
	int	i;
	int	j;
	int	k;

	i = map->startline;
	k = 0;
	size = map->nbline - map->startline;
	printf("size = %d\n", size);
	print_map(map->map);
	map->f_map = ft_calloc(sizeof(char *), size + 1);
	while (map->map[i])
	{
		j = 0;
		map->f_map[k] = ft_calloc(sizeof(char), map->sizeline + 2);
		while (j < map->sizeline)
		{
			if (map->map[i][j] == ' ' || map->map[i][j] == '\t' || map->map[i][j] == '\n' || map->map[i][j] == '\0')
 				map->f_map[k][j] = '1';
			else
				map->f_map[k][j] = map->map[i][j];
 			j++;
		}
		map->f_map[k][j] = '\n';
		map->f_map[k][++j] = '\0';
		i++;
		k++;
	}
	map->f_map[k] = NULL;
	printf("F_MAP\n");
	print_map(map->f_map);
	freetab(map->map);
}


