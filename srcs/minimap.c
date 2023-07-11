/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:52:08 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/11 15:57:45 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// MODIFIER CETTE FONCTION CAR ELLE ENVOIE LES IMAGES DANS LA WINDOW PRINCIPALE
// //IL FAUT ENVOYER LES POINTS DANS L'IMAGE QUI SERA CREEE POUR LA MINIMAP ET NON UNE WINDOZ ANNEXE
// void	display_img(t_glb *glb, int i, int j, void *img)
// {
// 	mlx_put_image_to_window(glb->mlx.mlx, glb->mlx.minimap, img, glb->mlx.length * j,
// 		glb->mlx.height * i);
// }

// int	display(t_glb *glb)
// {
// 	display_minimap(glb);
// 	return (0);
// }

// int	display_minimap(t_glb *glb)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (glb->map.f_map[i])
// 	{
// 		while (glb->map.f_map[i][j])
// 		{
// 			if (glb->map.f_map[i][j] == '1')
// 				display_img(glb, i, j, glb->mlx.img_wall);
// 			if (glb->map.f_map[i][j] == '0')
// 				display_img(glb, i, j, glb->mlx.img_floor);
// 			if (glb->map.f_map[i][j] == 'E')
// 				display_img(glb, i, j, glb->mlx.img_player);
// 			if (glb->map.f_map[i][j] == 'W')
// 				display_img(glb, i, j, glb->mlx.img_player);
// 			if (glb->map.f_map[i][j] == 'S')
// 				display_img(glb, i, j, glb->mlx.img_player);
//             if (glb->map.f_map[i][j] == 'N')
// 				display_img(glb, i, j, glb->mlx.img_player);
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	return (1);
// }