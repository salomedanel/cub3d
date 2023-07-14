/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:42 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/14 10:50:52 by tmichel-         ###   ########.fr       */
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
	rc->movespeed = 0.02;
	rc->raydirx = 0;
	rc->raydiry = 0;
	rc->sidedistx = 0;
	rc->sidedisty = 0;
	rc->drawend = 0;
	rc->drawstart = 0;
	rc->perpwalldist = 0.0;
	rc->side = 0;
	rc->stepx = 0;
	rc->stepy = 0;
	rc->hit = 0;
	rc->lineheight = 0;
}

void	get_e_w(t_rc *rc)
{
	if (rc->dir == 'E')
	{
		rc->dirx = 0;
		rc->diry = 1;
		rc->planex = 0.66;
		rc->planey = 0;
	}
	else if (rc->dir == 'W')
	{
		rc->dirx = 0;
		rc->diry = -1;
		rc->planex = -0.66;
		rc->planey = 0;
	}
}

void	get_orientation_full(t_rc *rc)
{
	if (rc->dir == 'N')
	{
		rc->dirx = -1;
		rc->diry = 0;
		rc->planex = 0;
		rc->planey = 0.66;
	}
	else if (rc->dir == 'S')
	{
		rc->dirx = 1;
		rc->diry = 0;
		rc->planex = 0;
		rc->planey = -0.66;
	}
	else
		get_e_w(rc);
}
