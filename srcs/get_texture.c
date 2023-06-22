/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:45:29 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/22 14:48:06 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_no(char *path, int *counter, char *direction, t_map *map)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (ft_strcmp(direction, "NO") == 0)
	{
		map->no = malloc(sizeof(char) * (ft_strlen(path) - 2));
		while (path[i] && path[i] == ' ')
			i++;
		while (path[i])
		{
			map->no[j] = path[i];
			i++;
			j++;
		}
		map->no[j] = '\0';
	}
	*counter = *counter + 1;
	return ;
}

void	get_texture_so(char *path, int *counter, char *direction, t_map *map)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (ft_strcmp(direction, "SO") == 0)
	{
		map->so = malloc(sizeof(char) * (ft_strlen(path) - 2));
		while (path[i] && path[i] == ' ')
			i++;
		while (path[i])
		{
			map->so[j] = path[i];
			i++;
			j++;
		}
		map->so[j] = '\0';
	}
	*counter = *counter + 1;
	return ;
}

void	get_texture_we(char *path, int *counter, char *direction, t_map *map)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (ft_strcmp(direction, "WE") == 0)
	{
		map->we = malloc(sizeof(char) * (ft_strlen(path) - 2));
		while (path[i] && path[i] == ' ')
			i++;
		while (path[i])
		{
			map->we[j] = path[i];
			i++;
			j++;
		}
		map->we[j] = '\0';
	}
	*counter = *counter + 1;
	return ;
}

void	get_texture_ea(char *path, int *counter, char *direction, t_map *map)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (ft_strcmp(direction, "EA") == 0)
	{
		map->ea = malloc(sizeof(char) * (ft_strlen(path) - 2));
		while (path[i] && path[i] == ' ')
			i++;
		while (path[i])
		{
			map->ea[j] = path[i];
			i++;
			j++;
		}
		map->ea[j] = '\0';
	}
	*counter = *counter + 1;
	return ;
}