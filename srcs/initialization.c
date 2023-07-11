/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:42 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/11 15:59:26 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_map *map, t_rc *rc)
{	
	int	i;

	i = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	while (rc->cmds[++i])
		rc->cmds[i] = 0;
	rc->posX = 0;
	rc->posY = 0;
	rc->moveSpeed = 0.1;
	rc->rayDirX = 0;
	rc->rayDirY = 0;
	rc->drawEnd = 0;
	rc->drawStart = 0;
	rc->cameraX	= 0;
	rc->deltaDistX = cos(rc->cameraX) * 5;
	rc->deltaDistY = sin(rc->cameraX) * 5;
	rc->perpWallDist = 0;
	rc->side = 0;
	rc->stepX = 0;
	rc->stepY = 0;
	rc->hit = 0;
	rc->lineHeight = 0;
}

void	get_e_w(t_rc *rc)
{
	if (rc->dir == 'E')
	{
		rc->dirX = 1;
		rc->dirY = 0;
		rc->planeX = 0;
		rc->planeY = 0.66;
	}
	else if (rc->dir == 'W')
	{
		rc->dirX = -1;
		rc->dirY = 0;
		rc->planeX = 0;
		rc->planeY = -0.66;
	}
}

void	get_orientation_full(t_rc *rc)
{
	if (rc->dir == 'N')
	{
		rc->dirX = 0;
		rc->dirY = -1;
		rc->planeX = 0.66;
		rc->planeY = 0;
	}
	else if (rc->dir == 'S')
	{
		rc->dirX = 0;
		rc->dirY = 1;
		rc->planeX = -0.66;
		rc->planeY = 0;
	}
	else
		get_e_w(rc);
}