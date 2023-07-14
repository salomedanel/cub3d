/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:54:48 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/14 10:51:13 by tmichel-         ###   ########.fr       */
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
		glb->rc->wallx = glb->rc->posy
			+ glb->rc->perpwalldist * glb->rc->raydiry;
	else
		glb->rc->wallx = glb->rc->posx
			+ glb->rc->perpwalldist * glb->rc->raydirx;
	glb->rc->wallx -= floor(glb->rc->wallx);
	glb->rc->texx = (int)(glb->rc->wallx * (double)TEXWIDTH);
	if (!glb->rc->side && glb->rc->raydirx > 0)
		glb->rc->texx = TEXWIDTH - glb->rc->texx - 1;
	if (glb->rc->side && glb->rc->raydiry < 0)
		glb->rc->texx = TEXWIDTH - glb->rc->texx - 1;
	glb->rc->step = 1.0 * TEXHEIGHT / glb->rc->lineheight;
	glb->rc->texpos = (glb->rc->drawstart - HEIGHT / 2
			+ glb->rc->lineheight / 2) * glb->rc->step;
}

void	get_wall(t_glb *glb, int x)
{
	int	color;
	int	y;

	y = glb->rc->drawstart;
	while (y < glb->rc->drawend)
	{
		glb->rc->texy = (int)glb->rc->texpos & (TEXHEIGHT - 1);
		glb->rc->texpos += glb->rc->step;
		if (!glb->rc->side && glb->rc->raydirx < 0)
			color = get_tex_color(glb->no_addr, glb->rc->texx,
					glb->rc->texy, glb->no_bits_per_pixel);
		if (!glb->rc->side && glb->rc->raydirx > 0)
			color = get_tex_color(glb->so_addr, glb->rc->texx,
					glb->rc->texy, glb->so_bits_per_pixel);
		if (glb->rc->side && glb->rc->raydiry < 0)
			color = get_tex_color(glb->we_addr, glb->rc->texx,
					glb->rc->texy, glb->we_bits_per_pixel);
		if (glb->rc->side && glb->rc->raydiry > 0)
			color = get_tex_color(glb->ea_addr, glb->rc->texx,
					glb->rc->texy, glb->ea_bits_per_pixel);
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
