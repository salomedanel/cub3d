/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:22:56 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/01 16:18:32 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_map *map, t_pos *ppos)
{	
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	ppos->x = 0;
	ppos->y = 0;
	ppos->dir = 0;
}

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

int	parsing(t_map *map, char **argv)
{
	t_pos	ppos;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size_map(map);
	get_map(map, argv);
	parse_texture(map, i, &ppos);
	parse_texture_path(map);
	parse_fc(map, i, j);
	check_emptyline(map);
	final_map(map, i);
	check_mapchar(map);
	get_playerpos(map, &ppos, i);
	map_outline(map, j);
	//print_map(map->f_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_glb	glb;

	map.file = check_arg(argc, argv);
	if (map.file < 0)
		return (-1);
	parsing(&map, argv);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (printf("Error\nPb init mlx\n"));
	init_window(&map, &mlx);
	window_minimap(&map, &mlx);
	init_img(&mlx);
	// glb.map.f_map = malloc(sizeof(char*) * (map.height + 1));
	// if (glb.map.f_map == NULL)
	// 	return (0);
	// for (int i = 0; i < map.height; i++)
	// {
   	// 	glb.map.f_map[i] = ft_strdup(map.f_map[i]);
    // 	if (glb.map.f_map[i] == NULL)
	// 		return (0);
	// }
	// glb.map.f_map[map.height] = NULL;
	// printf("%s\n", glb.map.f_map)
	mlx_loop_hook(mlx.mlx, &display, &mlx);
	mlx_hook(mlx.window, 17, 1L << 0, quit, &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.minimap, 17, 1L << 0, quit, &mlx);
	mlx_hook(mlx.minimap, 2, 1L << 0, key_press, &mlx);
	mlx_loop(mlx.mlx);
	//freetab(map.f_map);
	//free_texture(&map);
	return (0);
}
