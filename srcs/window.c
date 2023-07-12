/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/12 11:55:40 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_glb *glb)
{
	glb->mlx = mlx_init();
	if (glb->mlx == NULL)
		free(glb->mlx);
	glb->window = mlx_new_window(glb->mlx, WIDTH, HEIGHT, "cub3d");
	if (glb->window == NULL)
	{
		mlx_destroy_display(glb->mlx);
		free(glb->mlx);
	}
	glb->img = mlx_new_image(glb->mlx, WIDTH, HEIGHT);
	glb->addr = mlx_get_data_addr(glb->img,
			&glb->bits_per_pixel, &glb->line_length,
			&glb->endian);
	hooks(glb);
	mlx_loop(glb->mlx);
}

