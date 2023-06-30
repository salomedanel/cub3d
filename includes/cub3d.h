/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:23:46 by sdanel            #+#    #+#             */
/*   Updated: 2023/06/30 14:06:18 by sdanel           ###   ########.fr       */
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

// # define ERR_TXT "Error\nWrong or missing texture path."
# define ERR_PLACE "Error\nMap before texture or missing texture info.\n"
# define ERR_FC "Error\nWrong floor or ceiling color id.\n"

typedef struct s_map
{
	int		file;
	int		nbline;
	int		sizeline;
	int		startline;
	char	**map;
	char	**f_map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**f;
	char	**c;
	int		colors[6];
	int		height;
	int		lenght;
}			t_map;

typedef struct s_pos
{
	int		x;
	int		y;
	char	dir;
}		t_pos;

// get_map
int			start_map(t_map *map);
int			size_map(t_map *map);
void		cpy_map(t_map *map, char *line, int *i);
int			get_map(t_map *map, char **argv);
void		final_map(t_map *map, int k);

// parse_map
int			parse_texture(t_map *map, int counter, t_pos *ppos);
int			parse_fc(t_map *map, int fc_malloc, int i);
int			check_mapchar(t_map *map);
int			get_playerpos(t_map *map, t_pos *ppos, int counter);
int			map_outline(t_map *map, int i);

//get_texture
int			parse_texture_path(t_map *map);
void		get_texture_no(char *path, int *counter, char *direction,
				t_map *map);
void		get_texture_so(char *path, int *counter, char *direction,
				t_map *map);
void		get_texture_we(char *path, int *counter, char *direction,
				t_map *map);
void		get_texture_ea(char *path, int *counter, char *direction,
				t_map *map);

// parsing_utils00
int			contains_comma(char *str);
int			ft_unsigned_atoi(t_map *map, const char *nptr, int malloc);
void		print_map(char **map);
int			len_map(t_map *map);

// parsing_utils01
void		fill_colors(t_map *map, int fc_malloc, char c);
void		check_colors_value(t_map *map);
int			check_emptyline(t_map *map);

// main
void		init_data(t_map *map, t_pos *ppos);
int			check_file(char **argv, int file);
int			check_arg(int argc, char **argv);
int			parsing(t_map *map, char **argv);

// free
void		freetab(char **table);
void		free_texture(t_map *map);
int			exit_parserror(t_map *map, char *err);
int			exit_parserror2(t_map *map, char *err);

#endif
