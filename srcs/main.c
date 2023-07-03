/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:22:56 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/03 17:08:06 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_map *map, t_rc *rc)
{	
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	rc->x = 0;
	rc->y = 0;
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
	t_rc	rc;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size_map(map);
	get_map(map, argv);
	parse_texture(map, i, &rc);
	parse_texture_path(map);
	parse_fc(map, i, j);
	check_emptyline(map);
	final_map(map, i);
	check_mapchar(map);
	get_playerpos(map, &rc, i);
	map_outline(map, j);
	//print_map(map->f_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_glb	*glb;

	map.file = check_arg(argc, argv);
	if (map.file < 0)
		return (-1);
	parsing(&map, argv);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (printf("Error\nPb init mlx\n"));
	glb = malloc(sizeof(t_glb));
	if (!glb)
		return (0);
	glb->map = map;
	glb->mlx = mlx;
	init_window(glb);
	// window_minimap(glb);
	init_img(glb);
	mlx_loop_hook(mlx.mlx, &display, glb);
	mlx_hook(glb->mlx.window, 17, 1L << 0, quit, glb);
	mlx_hook(glb->mlx.window, 2, 1L << 0, key_press, glb);
	// mlx_hook(glb->mlx.minimap, 17, 1L << 0, quit, glb);
	// mlx_hook(glb->mlx.minimap, 2, 1L << 0, key_press, glb);
	mlx_loop(glb->mlx.mlx);
	return (0);
}
