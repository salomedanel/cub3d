/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:54:48 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/13 17:06:36 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_color(char *texData, int texx, int texy, int bpp)
{
	int				offset;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	*tex_pixel;

	offset = (texx * bpp / 8) + (texy * TEXWIDTH * bpp / 8);
	tex_pixel = (unsigned int *)(texData + offset);
	r = (*tex_pixel >> 16) & 0xFF;
	g = (*tex_pixel >> 8) & 0xFF;
	b = *tex_pixel & 0xFF;
	return ((r << 16) | (g << 8) | b);
}

void	get_tex(t_glb *glb)
{
	if (!glb->rc->side)
		glb->rc->wallX = glb->rc->posY
			+ glb->rc->perpWallDist * glb->rc->rayDirY;
	else
		glb->rc->wallX = glb->rc->posX
			+ glb->rc->perpWallDist * glb->rc->rayDirX;
	glb->rc->wallX -= floor(glb->rc->wallX);
	glb->rc->texX = (int)(glb->rc->wallX * (double)TEXWIDTH);
	if (!glb->rc->side && glb->rc->rayDirX > 0)
		glb->rc->texX = TEXWIDTH - glb->rc->texX - 1;
	if (glb->rc->side && glb->rc->rayDirY < 0)
		glb->rc->texX = TEXWIDTH - glb->rc->texX - 1;
	glb->rc->step = 1.0 * TEXHEIGHT / glb->rc->lineHeight;
	glb->rc->texPos = (glb->rc->drawStart - HEIGHT / 2
			+ glb->rc->lineHeight / 2) * glb->rc->step;
}

void	get_wall(t_glb *glb, int x)
{
	int	color;
	int	y;

	y = glb->rc->drawStart;
	while (y < glb->rc->drawEnd)
	{
		glb->rc->texY = (int)glb->rc->texPos & (TEXHEIGHT - 1);
		glb->rc->texPos += glb->rc->step;
		if (!glb->rc->side && glb->rc->rayDirX < 0)
			color = get_tex_color(glb->no_addr, glb->rc->texX,
					glb->rc->texY, glb->no_bits_per_pixel);
		if (!glb->rc->side && glb->rc->rayDirX > 0)
			color = get_tex_color(glb->so_addr, glb->rc->texX,
					glb->rc->texY, glb->so_bits_per_pixel);
		if (glb->rc->side && glb->rc->rayDirY < 0)
			color = get_tex_color(glb->we_addr, glb->rc->texX,
					glb->rc->texY, glb->we_bits_per_pixel);
		if (glb->rc->side && glb->rc->rayDirY > 0)
			color = get_tex_color(glb->ea_addr, glb->rc->texX,
					glb->rc->texY, glb->ea_bits_per_pixel);
		pixel_put(glb, x, y, color);
		y++;
	}
}

void	get_floor(t_glb *glb, int drawend, int x)
{
	int		y;
	int		converted_color;
	t_color	color;

	color = (t_color){
		.r = glb->map->colors[0],
		.g = glb->map->colors[1],
		.b = glb->map->colors[2]};
	converted_color = convert_hexa_color(color.r, color.g, color.b);
	y = drawend;
	while (y < HEIGHT)
		pixel_put(glb, x, y++, converted_color);
}

void	get_ceiling(t_glb *glb, int drawstart, int x)
{
	int		y;
	int		converted_color;
	t_color	color;

	color = (t_color){
		.r = glb->map->colors[3],
		.g = glb->map->colors[4],
		.b = glb->map->colors[5]};
	converted_color = convert_hexa_color(color.r, color.g, color.b);
	y = 0;
	while (y < drawstart)
		pixel_put(glb, x, y++, converted_color);
}
