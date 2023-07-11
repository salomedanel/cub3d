/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/11 23:34:06 by tmichel-         ###   ########.fr       */
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
	glb->img = malloc(sizeof(t_image));
	if (!glb->img)
		return ;
	glb->img->img = mlx_new_image(glb->mlx, WIDTH, HEIGHT);
	glb->img->addr = mlx_get_data_addr(glb->img->img,
			&glb->img->bits_per_pixel, &glb->img->line_length,
			&glb->img->endian);
	hooks(glb);
	mlx_loop(glb->mlx);
}

