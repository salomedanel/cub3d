/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/12 17:07:36 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_walls_ew(t_glb *glb, int w, int h)
{
	glb->ea_img = mlx_xpm_file_to_image(glb->mlx, glb->map->ea, &w, &h);
	if (!glb->ea_img)
		return ;
	glb->ea_addr = mlx_get_data_addr(glb->ea_img, &glb->ea_bits_per_pixel,
		&glb->ea_line_length, &glb->ea_endian);
	glb->we_img = mlx_xpm_file_to_image(glb->mlx, glb->map->we, &w, &h);
	if (!glb->we_img)
		return ;
	glb->we_addr = mlx_get_data_addr(glb->we_img, &glb->we_bits_per_pixel,
		&glb->we_line_length, &glb->we_endian);
}

void	init_all_walls(t_glb *glb)
{
	int	w;
	int	h;
	
	glb->no_img = mlx_xpm_file_to_image(glb->mlx, glb->map->no, &w, &h);
	if (!glb->no_img)
		return ;
	glb->no_addr = mlx_get_data_addr(glb->no_img, &glb->no_bits_per_pixel,
		&glb->no_line_length, &glb->no_endian);
	glb->so_img = mlx_xpm_file_to_image(glb->mlx, glb->map->so, &w, &h);
	if (!glb->so_img)
		return ;
	glb->so_addr = mlx_get_data_addr(glb->so_img, &glb->so_bits_per_pixel,
		&glb->so_line_length, &glb->so_endian);
	init_walls_ew(glb, w, h);
}

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
	init_all_walls(glb);
	hooks(glb);
	mlx_loop(glb->mlx);
}
