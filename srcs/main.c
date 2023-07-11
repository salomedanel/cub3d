/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:22:56 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/11 23:36:50 by tmichel-         ###   ########.fr       */
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

t_rc	*parsing(t_map *map, char **argv)
{
	t_rc	*rc;
	int		i;
	int		j;

	i = 0;
	j = -1;
	rc = malloc(sizeof(t_rc));
	if (!rc)
		return (0);
	size_map(map);
	get_map(map, argv);
	parse_texture(map, i, rc);
	parse_texture_path(map);
	parse_fc(map, i, j);
	check_emptyline(map);
	final_map(map, i);
	check_mapchar(map);
	get_playerpos(map, rc, i);
	map_outline(map, j);
	return (rc);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_glb	*glb;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->file = check_arg(argc, argv);
	if (map->file < 0)
		return (-1);
	glb = malloc(sizeof(t_glb));
	if (!glb)
		return (0);
	glb->rc = parsing(map, argv);
	glb->map = map;
	init_window(glb);
	return (0);
}
