/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:12:07 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/12 11:58:01 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_image	*init_img(void *mlx)
// {
// 	t_image	*img;

// 	img = malloc(sizeof(t_image));
// 	if (!img)
// 		return ((t_image *)(0));
// 	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!img->img)
// 		return ((t_image *)(0));
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
// 			&img->line_length, &img->endian);

// 	return (img);
// }

void	pixel_put(t_glb *glb, int x, int y, int color)
{
	char	*dst;
	
	dst = glb->addr + (y * glb->line_length + x * (glb->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
