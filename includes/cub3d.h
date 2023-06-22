/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:23:46 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/22 14:56:16 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_TXT "Error\nWrong texture path or map before texture."

typedef struct s_map
{
	int		file;
	int		nbline;
	int		sizeline;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			t_map;

// get_map
int			size_map(t_map *map);
void		cpy_map(t_map *map, char *line, int *i);
int			get_map(t_map *map, char **argv);
void		print_map(char **map);

// parse_map
int			start_map(t_map *map);
int			parse_texture(t_map *map);
int			parse_texture_path(t_map *map);

//get_texture
void		get_texture_no(char *path, int *counter, char *direction,
				t_map *map);
void		get_texture_so(char *path, int *counter, char *direction,
				t_map *map);
void		get_texture_we(char *path, int *counter, char *direction,
				t_map *map);
void		get_texture_ea(char *path, int *counter, char *direction,
				t_map *map);

// main
int			check_file(char **argv, int file);
int			check_arg(int argc, char **argv);

// free
void		freetab(char **table);

#endif