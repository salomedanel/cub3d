/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:47 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/13 11:33:19 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_texture(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
}

int	exit_parserror(t_map *map, char *err)
{
	ft_printf("%s", err);
	if (map->map)
		freetab(map->map);
	free_texture(map);
	exit (0);
}

int	exit_parserror2(t_map *map, char *err)
{
	ft_printf("%s", err);
	if (map->map)
		freetab(map->f_map);
	free_texture(map);
	exit (0);
}

int	quit(t_glb *glb)
{
	mlx_destroy_image(glb->mlx, glb->no_img);
	mlx_destroy_image(glb->mlx, glb->ea_img);
	mlx_destroy_image(glb->mlx, glb->we_img);
	mlx_destroy_image(glb->mlx, glb->so_img);
	mlx_destroy_image(glb->mlx, glb->img);
	mlx_destroy_window(glb->mlx, glb->window);
	mlx_destroy_display(glb->mlx);
	free(glb->mlx);
	free_map(glb->map);
	free(glb->rc);
	free(glb->map);
	free(glb);
	exit(0);
}