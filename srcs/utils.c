/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:48:18 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/14 10:53:31 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_deltadist(float raydir)
{
	float	deltadist;

	deltadist = 0.0;
	if (raydir == 0)
		return (deltadist = 2147483647.0);
	else
		return (deltadist = fabs(1 / raydir));
}

int	convert_hexa_color(int red, int green, int blue)
{
	int	hex_value;

	hex_value = 0;
	hex_value |= red << 16;
	hex_value |= green << 8;
	hex_value |= blue;
	return (hex_value);
}

void	pixel_put(t_glb *glb, int x, int y, int color)
{
	char	*dst;

	dst = glb->addr + (y * glb->line_length + x * (glb->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
