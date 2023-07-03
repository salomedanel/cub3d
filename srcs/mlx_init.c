/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:17 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/03 17:24:52 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_glb *glb)
{
	glb->mlx.window = mlx_new_window(glb->mlx.mlx, glb->map.lenght * 64, glb->map.height * 64,
			"cub3d");
	if (glb->mlx.window == NULL)
	{
		free(glb->mlx.mlx);
		printf("Err window\n");
	}
	else
		printf("Window open\n");
}

void	window_minimap(t_glb *glb)
{
	glb->mlx.minimap = mlx_new_window(glb->mlx.mlx, glb->map.lenght * 10, glb->map.height * 10,
			"minimap");
	if (glb->mlx.minimap == NULL)
	{
		free(glb->mlx.mlx);
		printf("Err window\n");
	}
	else
		printf("Minimap open\n");
}
void	init_img(t_glb *glb)
{
	glb->mlx.img_wall = mlx_xpm_file_to_image(glb->mlx.mlx, WALL, &glb->mlx.lenght,
			&glb->mlx.height);
	glb->mlx.img_floor = mlx_xpm_file_to_image(glb->mlx.mlx, FLOOR, &glb->mlx.lenght,
			&glb->mlx.height);
	glb->mlx.img_player = mlx_xpm_file_to_image(glb->mlx.mlx, PLAYER, &glb->mlx.lenght,
			&glb->mlx.height);
}

int	key_press(int keycode, t_glb *glb)
{
	if (keycode == XK_Escape)
		quit(glb);
	return (0);
}