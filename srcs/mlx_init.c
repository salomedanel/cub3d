/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/30 15:59:46 by sdanel           ###   ########.fr       */
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