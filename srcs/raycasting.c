/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:50 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/12 14:36:15 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rc(t_glb *glb, int i)
{
	glb->rc->cameraX = 2 * i / (float)WIDTH - 1;
	glb->rc->rayDirX = glb->rc->dirX + glb->rc->planeX * glb->rc->cameraX;
	glb->rc->rayDirY = glb->rc->dirY + glb->rc->planeY * glb->rc->cameraX;
	glb->rc->mapX = (int)glb->rc->posX;
	glb->rc->mapY = (int)glb->rc->posY;
	glb->rc->deltaDistX = get_deltadist(glb->rc->rayDirX);
	glb->rc->deltaDistY = get_deltadist(glb->rc->rayDirY);
}

void	step_sidedist(t_glb *glb)
{
	if (glb->rc->rayDirX < 0)
	{
		glb->rc->stepX = -1;
		glb->rc->sideDistX = (glb->rc->posX - glb->rc->mapX) * glb->rc->deltaDistX;
	}
	else
	{
		glb->rc->stepX = 1;
		glb->rc->sideDistX = (glb->rc->mapX + 1.0 - glb->rc->posX) * glb->rc->deltaDistX;	
	}
	if (glb->rc->rayDirY < 0)
	{
		glb->rc->stepY = -1;
		glb->rc->sideDistY = (glb->rc->posY - glb->rc->mapY) * glb->rc->deltaDistY;
	}
	else
	{
		glb->rc->stepY = 1;
		glb->rc->sideDistY = (glb->rc->mapY +1.0 - glb->rc->posY) * glb->rc->deltaDistY;	
	}
	glb->rc->hit = 0;
}

void	dda(t_glb *glb)
{
	while (glb->rc->hit == 0)
	{
		if (glb->rc->sideDistX < glb->rc->sideDistY)
		{
			glb->rc->sideDistX += glb->rc->deltaDistX;
			glb->rc->mapX += glb->rc->stepX;
			glb->rc->side = 0;
		}
		else
		{
			glb->rc->sideDistY += glb->rc->deltaDistY;
			glb->rc->mapY += glb->rc->stepY;
			glb->rc->side = 1;
		}
		if (glb->map->f_map[glb->rc->mapX][glb->rc->mapY] == '1')
			glb->rc->hit = 1;
	}
}

void	draw_on_screen(t_glb *glb)
{
	if (!glb->rc->side)
	{
		glb->rc->perpWallDist = glb->rc->sideDistX - glb->rc->deltaDistX;
		printf("sideDistX is %f\n", glb->rc->sideDistX);
		printf("deltaDistX is %f\n", glb->rc->deltaDistX);
	}
	else
		glb->rc->perpWallDist = glb->rc->sideDistY - glb->rc->deltaDistY;
	// if (glb->rc->perpWallDist == 0)
	// 	glb->rc->perpWallDist = 1;
	glb->rc->lineHeight = (int)(HEIGHT / glb->rc->perpWallDist);
	// printf("lineHeight is %d\n", glb->rc->lineHeight);
	// printf("perpWallDist is %f\n", glb->rc->perpWallDist);
	glb->rc->drawStart = -glb->rc->lineHeight / 2 + HEIGHT / 2;
	// printf("drawstart is %d\n", glb->rc->drawStart);
	if (glb->rc->drawStart < 0)
		glb->rc->drawStart = 0;
	glb->rc->drawEnd = glb->rc->lineHeight / 2 + HEIGHT / 2;
	if (glb->rc->drawEnd > HEIGHT)
		glb->rc->drawEnd = HEIGHT - 1;
	// printf("drawend is %d\n", glb->rc->drawEnd);
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
		get_floor(glb, glb->rc->drawEnd, i);
		get_ceiling(glb, glb->rc->drawStart, i);
	}
	mlx_put_image_to_window(glb->mlx, glb->window, glb->img, 0, 0);
}