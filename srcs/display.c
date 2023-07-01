/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:52:08 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/01 16:16:14 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_img(t_mlx *mlx, int i, int j, void *img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, img, mlx->lenght * j,
		mlx->height * i);
}

int	display(t_glb *glb)
{
	display_minimap(glb);
	return (0);
}

int	display_minimap(t_glb *glb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%s\n", glb->map.f_map[0]);
	while (glb->map.f_map[i])
	{
		while (glb->map.f_map[i][j])
		{
			printf("i = %d | j = %d | char = %c\n", i, j, glb->map.f_map[i][j]);
			if (glb->map.f_map[i][j] == '1')
				display_img(&glb->mlx, i, j, glb->mlx.img_wall);
			if (glb->map.f_map[i][j] == '0')
				display_img(&glb->mlx, i, j, glb->mlx.img_floor);
			if (glb->map.f_map[i][j] == 'E')
				display_img(&glb->mlx, i, j, glb->mlx.img_player);
			if (glb->map.f_map[i][j] == 'W')
				display_img(&glb->mlx, i, j, glb->mlx.img_player);
			if (glb->map.f_map[i][j] == 'S')
				display_img(&glb->mlx, i, j, glb->mlx.img_player);
            if (glb->map.f_map[i][j] == 'N')
				display_img(&glb->mlx, i, j, glb->mlx.img_player);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}