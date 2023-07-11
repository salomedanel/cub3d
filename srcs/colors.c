/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:54:48 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/11 16:53:49 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_floor(t_glb *glb)
{
	t_color	color;
	
	color = (t_color){
		.r = glb->map.colors[0],
		.g = glb->map.colors[1],
		.b = glb->map.colors[2]};
	return(color.hex);
}

int	color_ceiling(t_glb *glb)
{
	t_color	color;
	
	color = (t_color){
		.r = glb->map.colors[3],
		.g = glb->map.colors[4],
		.b = glb->map.colors[5]};
	return(color.hex);
}

void	get_floor(t_glb *glb, int drawend, int x)
{
	int	y;
	int	color;

	color = color_floor(glb);
	y = drawend - 1;
	while (++y < HEIGHT)
		pixel_put(&glb->img, x, y, color);
}

void	get_ceiling(t_glb *glb, int drawstart, int x)
{
	int	y;
	int	color;

	color = color_floor(glb);
	y = -1;
	while (++y < drawstart)
		pixel_put(&glb->img, x, y, color);
}