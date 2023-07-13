/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:27:34 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/13 08:45:24 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_glb *glb)
{
	glb->rc->oldDirX = glb->rc->dirX;
	glb->rc->dirX = glb->rc->dirX 
		* cos(-glb->rc->moveSpeed) - glb->rc->dirY * sin(-glb->rc->moveSpeed);
	glb->rc->dirY = glb->rc->oldDirX
		* sin(-glb->rc->moveSpeed) + glb->rc->dirY * cos(-glb->rc->moveSpeed);
	glb->rc->oldPlaneX = glb->rc->planeX;
	glb->rc->planeX = glb->rc->planeX 
		* cos(-glb->rc->moveSpeed) - glb->rc->planeY * sin(-glb->rc->moveSpeed);
	glb->rc->planeY = glb->rc->oldPlaneX 
		* sin(-glb->rc->moveSpeed) + glb->rc->planeY * cos(-glb->rc->moveSpeed);
}

void	rotate_right(t_glb *glb)
{
	glb->rc->oldDirX = glb->rc->dirX;
	glb->rc->dirX = glb->rc->dirX 
		* cos(glb->rc->moveSpeed) - glb->rc->dirY * sin(glb->rc->moveSpeed);
	glb->rc->dirY = glb->rc->oldDirX
		* sin(glb->rc->moveSpeed) + glb->rc->dirY * cos(glb->rc->moveSpeed);
	glb->rc->oldPlaneX = glb->rc->planeX;
	glb->rc->planeX = glb->rc->planeX 
		* cos(glb->rc->moveSpeed) - glb->rc->planeY * sin(glb->rc->moveSpeed);
	glb->rc->planeY = glb->rc->oldPlaneX
		* sin(glb->rc->moveSpeed) + glb->rc->planeY * cos(glb->rc->moveSpeed);
}