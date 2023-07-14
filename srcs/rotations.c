/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:27:34 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/14 10:50:36 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_glb *glb)
{
	glb->rc->olddirx = glb->rc->dirx;
	glb->rc->dirx = glb->rc->dirx
		* cos(-glb->rc->movespeed) - glb->rc->diry * sin(-glb->rc->movespeed);
	glb->rc->diry = glb->rc->olddirx
		* sin(-glb->rc->movespeed) + glb->rc->diry * cos(-glb->rc->movespeed);
	glb->rc->oldplanex = glb->rc->planex;
	glb->rc->planex = glb->rc->planex
		* cos(-glb->rc->movespeed) - glb->rc->planey * sin(-glb->rc->movespeed);
	glb->rc->planey = glb->rc->oldplanex
		* sin(-glb->rc->movespeed) + glb->rc->planey * cos(-glb->rc->movespeed);
}

void	rotate_left(t_glb *glb)
{
	glb->rc->olddirx = glb->rc->dirx;
	glb->rc->dirx = glb->rc->dirx
		* cos(glb->rc->movespeed) - glb->rc->diry * sin(glb->rc->movespeed);
	glb->rc->diry = glb->rc->olddirx
		* sin(glb->rc->movespeed) + glb->rc->diry * cos(glb->rc->movespeed);
	glb->rc->oldplanex = glb->rc->planex;
	glb->rc->planex = glb->rc->planex
		* cos(glb->rc->movespeed) - glb->rc->planey * sin(glb->rc->movespeed);
	glb->rc->planey = glb->rc->oldplanex
		* sin(glb->rc->movespeed) + glb->rc->planey * cos(glb->rc->movespeed);
}
