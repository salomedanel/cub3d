/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/01 14:50:43 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_map *map, t_mlx *mlx)
{
	printf("lenght = %d | height = %d\n", map->lenght, map->height);
	mlx->window = mlx_new_window(mlx->mlx, map->lenght * 64, map->height * 64,
			"CUB3D");
	if (mlx->window == NULL)
	{
		free(mlx->mlx);
		printf("Err window\n");
	}
	else
		printf("Window open\n");
}

void	window_minimap(t_map *map, t_mlx *mlx)
{
	mlx->minimap = mlx_new_window(mlx->mlx, map->lenght * 10, map->height * 10,
			"minimap");
	if (mlx->minimap == NULL)
	{
		free(mlx->mlx);
		printf("Err window\n");
	}
	else
		printf("Minimap open\n");
}

void	init_img(t_mlx *mlx)
{
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, WALL, &mlx->lenght,
			&mlx->height);
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx, FLOOR, &mlx->lenght,
			&mlx->height);
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx, PLAYER, &mlx->lenght,
			&mlx->height);
}

int	key_press(int keycode, t_glb *glb)
{
	if (keycode == XK_Escape)
		quit(glb);
	return (0);
}