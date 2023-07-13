/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:42 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/13 16:24:45 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_map *map, t_rc *rc)
{	
	int	i;

	i = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	while (i < 6)
		rc->cmds[i++] = 0;
	rc->moveSpeed = 0.02;
	rc->rayDirX = 0;
	rc->rayDirY = 0;
	rc->sideDistX = 0;
	rc->sideDistY = 0;
	rc->drawEnd = 0;
	rc->drawStart = 0;
	rc->perpWallDist = 0.0;
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
		rc->dirX = 0;
		rc->dirY = 1;
		rc->planeX = 0.66;
		rc->planeY = 0;
	}
	else if (rc->dir == 'W')
	{
		rc->dirX = 0;
		rc->dirY = -1;
		rc->planeX = -0.66;
		rc->planeY = 0;
	}
}

void	get_orientation_full(t_rc *rc)
{
	if (rc->dir == 'N')
	{
		rc->dirX = -1;
		rc->dirY = 0;
		rc->planeX = 0;
		rc->planeY = 0.66;
	}
	else if (rc->dir == 'S')
	{
		rc->dirX = 1;
		rc->dirY = 0;
		rc->planeX = 0;
		rc->planeY = -0.66;
	}
	else
		get_e_w(rc);
}
