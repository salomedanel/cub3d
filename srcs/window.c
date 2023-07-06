/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/06 12:30:44 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_glb *glb)
{
	glb->mlx.window = mlx_new_window(glb->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (glb->mlx.window == NULL)
	{
		free(glb->mlx.mlx);
		printf("Err window\n");
	}
	else
		printf("Window open\n");
}

