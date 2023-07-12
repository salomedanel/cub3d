/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:22:32 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/12 18:08:16 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_glb *glb)
{
	glb->rc->newPosX = glb->rc->posX + glb->rc->dirX * glb->rc->moveSpeed;
	glb->rc->newPosY = glb->rc->posY + glb->rc->dirY * glb->rc->moveSpeed;
	if (glb->map->f_map[(int)glb->rc->newPosX][(int)glb->rc->posY] != '1')
		glb->rc->posX = glb->rc->newPosX;
	if (glb->map->f_map[(int)glb->rc->posX][(int)glb->rc->newPosY] != '1')
		glb->rc->posY = glb->rc->newPosY;
}

void	go_backward(t_glb *glb)
{
	glb->rc->newPosX = glb->rc->posX - glb->rc->dirX * glb->rc->moveSpeed;
	glb->rc->newPosY = glb->rc->posY - glb->rc->dirY * glb->rc->moveSpeed;
	if (glb->map->f_map[(int)glb->rc->newPosX][(int)glb->rc->posY] != '1')
		glb->rc->posX = glb->rc->newPosX;
	if (glb->map->f_map[(int)glb->rc->posX][(int)glb->rc->newPosY] != '1')
		glb->rc->posY = glb->rc->newPosY;
}

void	go_left(t_glb *glb)
{
	glb->rc->newPosX = glb->rc->posX - glb->rc->dirY * glb->rc->moveSpeed;
	glb->rc->newPosY = glb->rc->posY + glb->rc->dirX * glb->rc->moveSpeed;
	if (glb->map->f_map[(int)glb->rc->newPosX][(int)glb->rc->posY] != '1')
		glb->rc->posX = glb->rc->newPosX;
	if (glb->map->f_map[(int)glb->rc->posX][(int)glb->rc->newPosY] != '1')
		glb->rc->posY = glb->rc->newPosY;
}

void	go_right(t_glb *glb)
{
	glb->rc->newPosX = glb->rc->posX + glb->rc->dirY * glb->rc->moveSpeed;
	glb->rc->newPosY = glb->rc->posY - glb->rc->dirX * glb->rc->moveSpeed;
	if (glb->map->f_map[(int)glb->rc->newPosX][(int)glb->rc->posY] != '1')
		glb->rc->posX = glb->rc->newPosX;
	if (glb->map->f_map[(int)glb->rc->posX][(int)glb->rc->newPosY] != '1')
		glb->rc->posY = glb->rc->newPosY;
}