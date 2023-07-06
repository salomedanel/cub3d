/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:47 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/06 13:28:00 by tmichel-         ###   ########.fr       */
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
	mlx_destroy_window(glb->mlx.mlx, glb->mlx.window);
	mlx_destroy_display(glb->mlx.mlx);
	free(glb->mlx.mlx);
	free_map(&glb->map);
	exit(0);
}