/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:22:56 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/22 14:55:58 by sdanel           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	map;

	map.file = check_arg(argc, argv);
	if (map.file < 0)
		return (-1);
	if (size_map(&map) == -1)
		return (0);
	get_map(&map, argv);
	print_map(map.map);
	if (parse_texture(&map) == -1)
		return (0);
	if (parse_texture_path(&map) == -1)
		return (0);
	freetab(map.map);
	return (0);
}
