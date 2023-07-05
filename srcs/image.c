/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:12:07 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/05 16:30:42 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*init_img(void *mlx)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return ((t_image *)0);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img->img)
		return ((t_image *)0);
	img->addr = mlx_get_adata_ddr(img->img, &img->bits_per_pixels,
			&img->line_lenght, &img->endian);
	return (img);
}

void	pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;
	dst= img->addr + (y + img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
