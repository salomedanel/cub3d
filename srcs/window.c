/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/11 16:43:16 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_glb *glb)
{
	glb->mlx.window = mlx_new_window(glb->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (glb->mlx.window == NULL)
		free(glb->mlx.mlx);
	glb->img = init_img(glb->mlx.mlx);
	pixel_put(&glb->img, 10, 10, 0x00FF0000);
	hooks(glb);
	mlx_loop(glb->mlx.mlx);
}

