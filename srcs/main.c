/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:22:56 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/15 16:04:02 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char **argv, int file)
{
	file = open(argv[1], O_DIRECTORY);
	if (file > 0)
		return (printf("Error\nFile is a directory\n"), -1);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (printf("Error\nFile not found or permission denied\n"), -1);
	return (file);
}

int	check_arg(int argc, char **argv)
{
	int	file;
	int	argv_len;

	file = 0;
	if (argc != 2)
		return (printf("Error\nWrong number of arguments\n"), -1);
	else
	{
		argv_len = ft_strlen(argv[1]) - 1;
		if (argv[1][argv_len] == 'b')
			argv_len--;
		if (argv[1][argv_len] == 'u')
			argv_len--;
		if (argv[1][argv_len] == 'c')
			argv_len--;
		if (argv[1][argv_len] == '.')
			argv_len--;
		if (argv_len != ft_strlen(argv[1]) - 5)
			return (printf("Error\nWrong file extension\n"), -1);
		file = check_file(argv, file);
		return (file);
	}
}

int	size_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
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
		//printf("%s", line);
	}
	free(line);
	if (map->nbline < 9)
	{
		close(map->file);
		//free(line);
		return (printf("Error\nIncomplete file: missing info or map\n"), -1);
	}
	return (0);
}

int	get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	map->map = malloc(sizeof(char *) * map->nbline);
	if (map->map == NULL)
		return (printf("Error\nMalloc failed\n"), -1);
	line = get_next_line(map->file, 0);
	while (line)
	{
		map->map[i] = malloc(sizeof(char) * map->sizeline);
		line = get_next_line(map->file, 0);
		ft_strlcpy(map->map[i], line, map->sizeline);
		printf("%s\n", map->map[i]);
		free(line);
		i++;
	}
	free(line);
	map->map[i] = NULL;
	close(map->file);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.file = check_arg(argc, argv);
	if (map.file < 0)
		return (-1);
	if (size_map(&map) == -1)
		return (0);
	get_map(&map);
	freetab(map.map);
	return (0);
}
