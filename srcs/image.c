/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:12:07 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/12 12:24:50 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_glb *glb, int x, int y, int color)
{
	char	*dst;
	
	dst = glb->addr + (y * glb->line_length + x * (glb->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
