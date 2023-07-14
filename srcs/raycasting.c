/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:50 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/14 10:50:52 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rc(t_glb *glb, int i)
{
	glb->rc->camerax = 2 * i / (float)WIDTH - 1;
	glb->rc->raydirx = glb->rc->dirx + glb->rc->planex * glb->rc->camerax;
	glb->rc->raydiry = glb->rc->diry + glb->rc->planey * glb->rc->camerax;
	glb->rc->mapx = abs((int)glb->rc->posx);
	glb->rc->mapy = abs((int)glb->rc->posy);
	glb->rc->deltadistx = get_deltadist(glb->rc->raydirx);
	glb->rc->deltadisty = get_deltadist(glb->rc->raydiry);
}

void	step_sidedist(t_glb *glb)
{
	if (glb->rc->raydirx < 0)
	{
		glb->rc->stepx = -1;
		glb->rc->sidedistx = (glb->rc->posx - glb->rc->mapx)
			* glb->rc->deltadistx;
	}
	else
	{
		glb->rc->stepx = 1;
		glb->rc->sidedistx = (glb->rc->mapx + 1.0 - glb->rc->posx)
			* glb->rc->deltadistx;
	}
	if (glb->rc->raydiry < 0)
	{
		glb->rc->stepy = -1;
		glb->rc->sidedisty = (glb->rc->posy - glb->rc->mapy)
			* glb->rc->deltadisty;
	}
	else
	{
		glb->rc->stepy = 1;
		glb->rc->sidedisty = (glb->rc->mapy +1.0 - glb->rc->posy)
			* glb->rc->deltadisty;
	}
}

void	dda(t_glb *glb)
{
	glb->rc->hit = 0;
	while (glb->rc->hit == 0)
	{
		if (glb->rc->sidedistx < glb->rc->sidedisty)
		{
			glb->rc->sidedistx += glb->rc->deltadistx;
			glb->rc->mapx += glb->rc->stepx;
			glb->rc->side = 0;
		}
		else
		{
			glb->rc->sidedisty += glb->rc->deltadisty;
			glb->rc->mapy += glb->rc->stepy;
			glb->rc->side = 1;
		}
		if (glb->map->f_map[glb->rc->mapx][glb->rc->mapy] == '1')
			glb->rc->hit = 1;
	}
}

void	draw_on_screen(t_glb *glb)
{
	if (!glb->rc->side)
		glb->rc->perpwalldist = (glb->rc->mapx - glb->rc->posx
				+ (1 - glb->rc->stepx) / 2) / glb->rc->raydirx;
	else
		glb->rc->perpwalldist = (glb->rc->mapy - glb->rc->posy
				+ (1 - glb->rc->stepy) / 2) / glb->rc->raydiry;
	glb->rc->lineheight = (int)(HEIGHT / glb->rc->perpwalldist);
	glb->rc->drawstart = -glb->rc->lineheight / 2 + HEIGHT / 2;
	if (glb->rc->drawstart < 0)
		glb->rc->drawstart = 0;
	if (glb->rc->drawstart > HEIGHT)
		glb->rc->drawstart = HEIGHT - 1;
	glb->rc->drawend = glb->rc->lineheight / 2 + HEIGHT / 2;
	if (glb->rc->drawend >= HEIGHT)
		glb->rc->drawend = HEIGHT - 1;
	if (glb->rc->drawend < 0)
		glb->rc->drawend = 0;
}

void	raycasting_loop(t_glb *glb)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
	{
		init_rc(glb, i);
		step_sidedist(glb);
		dda(glb);
		draw_on_screen(glb);
		get_tex(glb);
		get_wall(glb, i);
		get_floor(glb, glb->rc->drawend, i);
		get_ceiling(glb, glb->rc->drawstart, i);
	}
	mlx_put_image_to_window(glb->mlx, glb->window, glb->img, 0, 0);
}
