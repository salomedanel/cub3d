/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:22:32 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/14 10:50:36 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_glb *glb)
{
	glb->rc->newposx = glb->rc->posx + glb->rc->dirx * glb->rc->movespeed;
	glb->rc->newposy = glb->rc->posy + glb->rc->diry * glb->rc->movespeed;
	if (glb->map->f_map[(int)glb->rc->newposx][(int)glb->rc->posy] != '1')
		glb->rc->posx = glb->rc->newposx;
	if (glb->map->f_map[(int)glb->rc->posx][(int)glb->rc->newposy] != '1')
		glb->rc->posy = glb->rc->newposy;
}

void	go_backward(t_glb *glb)
{
	glb->rc->newposx = glb->rc->posx - glb->rc->dirx * glb->rc->movespeed;
	glb->rc->newposy = glb->rc->posy - glb->rc->diry * glb->rc->movespeed;
	if (glb->map->f_map[(int)glb->rc->newposx][(int)glb->rc->posy] != '1')
		glb->rc->posx = glb->rc->newposx;
	if (glb->map->f_map[(int)glb->rc->posx][(int)glb->rc->newposy] != '1')
		glb->rc->posy = glb->rc->newposy;
}

void	go_left(t_glb *glb)
{
	glb->rc->newposx = glb->rc->posx - glb->rc->diry * glb->rc->movespeed;
	glb->rc->newposy = glb->rc->posy + glb->rc->dirx * glb->rc->movespeed;
	if (glb->map->f_map[(int)glb->rc->newposx][(int)glb->rc->posy] != '1')
		glb->rc->posx = glb->rc->newposx;
	if (glb->map->f_map[(int)glb->rc->posx][(int)glb->rc->newposy] != '1')
		glb->rc->posy = glb->rc->newposy;
}

void	go_right(t_glb *glb)
{
	glb->rc->newposx = glb->rc->posx + glb->rc->diry * glb->rc->movespeed;
	glb->rc->newposy = glb->rc->posy - glb->rc->dirx * glb->rc->movespeed;
	if (glb->map->f_map[(int)glb->rc->newposx][(int)glb->rc->posy] != '1')
		glb->rc->posx = glb->rc->newposx;
	if (glb->map->f_map[(int)glb->rc->posx][(int)glb->rc->newposy] != '1')
		glb->rc->posy = glb->rc->newposy;
}
