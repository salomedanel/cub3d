/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:50 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/04 17:16:28 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_raycasting(t_glb *glb, int x)
{
    glb->rc.mapX = abs((int)glb->rc.posX);
    glb->rc.mapY = abs((int)glb->rc.posY);
    glb->rc.cameraX = 2 * x / (float)WIDTH -1;
    glb->rc.rayDirX = glb->rc.dirX + glb->rc.planeX *  glb->rc.cameraX
    glb->rc.rayDirY = glb->rc.dirY + glb->rc.planeY *  glb->rc.cameraX
    
}