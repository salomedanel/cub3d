/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:23:46 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/06 17:05:06 by tmichel-         ###   ########.fr       */
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
# include <math.h>

// # define ERR_TXT "Error\nWrong or missing texture path."
# define ERR_PLACE "Error\nMap before texture or missing texture info.\n"
# define ERR_FC "Error\nWrong floor or ceiling color id.\n"
# define WALL "./texture/floor.xpm"
# define FLOOR "./texture/pwall.xpm"
# define PLAYER "./texture/exit.xpm"
# define WIDTH 1000
# define HEIGHT 1000


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
	int		length;
}			t_map;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*minimap;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	int		height;
	int		length;
}			t_mlx;

typedef struct s_rc
{
	char	dir;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	posX;
	double	posY;
	double	newPosX;
	double	newPosY;
	double	dirX;
	double	dirY;
	double	oldDirX;
	double	planeX;
	double	planeY;
	double	oldPlaneX;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	double	moveSpeed;
	double	perpWallDist;
	double	time;
	double	oldtime;
}		t_rc;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef	struct	s_glb
{
	t_map	map;
	t_mlx	mlx;
	t_rc	rc;
	t_image	img;
}				t_glb;

// main
void		init_data(t_map *map, t_rc *rc);
int			check_file(char **argv, int file);
int			check_arg(int argc, char **argv);
int			parsing(t_map *map, char **argv);

// get_map
int			start_map(t_map *map);
int			size_map(t_map *map);
void		cpy_map(t_map *map, char *line, int *i);
int			get_map(t_map *map, char **argv);
void		final_map(t_map *map, int k);

// parse_map
int			parse_texture(t_map *map, int counter, t_rc *rc);
int			parse_fc(t_map *map, int fc_malloc, int i);
int			check_mapchar(t_map *map);
int			get_playerpos(t_map *map, t_rc *rc, int counter);
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

// window
void		init_window(t_glb *glb);

//hooks
int			key_press(int keycode, t_glb *glb);

//image
t_image		*init_img(void *glb);
void		pixel_put(t_image *img, int x, int y, int color);

// minimap
void		display_img(t_glb *glb, int i, int j, void *img);
int			display(t_glb *glb);
int			display_minimap(t_glb *glb);

// free00
void		freetab(char **table);
void		free_texture(t_map *map);
int			exit_parserror(t_map *map, char *err);
int			exit_parserror2(t_map *map, char *err);
int			quit(t_glb *glb);

//free01
void		free_map(t_map *map);
void		free_mlx(t_mlx *mlx);

//raycasting
void		init_rc(t_glb *glb, int i);
void		step_sidedist(t_glb *glb);
void		dda(t_glb *glb);
void		draw_on_screen(t_glb *glb);
void		raycasting_loop(t_glb *glb);

//raycasting_utils
float   	get_deltadist(float raydir);

//colors

//moves
void		go_forward(t_glb *glb);
void		go_backward(t_glb *glb);
void		go_left(t_glb *glb);
void		go_right(t_glb *glb);

//rotations
void		rotate_right(t_glb *glb);
void		rotate_left(t_glb *glb);

#endif
