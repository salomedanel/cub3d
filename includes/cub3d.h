/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:23:46 by sdanel            #+#    #+#             */
/*   Updated: 2023/07/13 16:33:01 by tmichel-         ###   ########.fr       */
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
# define HEIGHT 500
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define W 119
# define S 115
# define A 97
# define D 100


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
	int		cmds[6];
	int		texX;
	int		texY;
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
	double	wallX;
	double	step;
	double	texPos;
	
}		t_rc;

typedef union	s_color
{
	unsigned int	hex;
	struct
	{
		int	r;
		int	g;
		int	b;
	};
}	t_color;

typedef	struct	s_glb
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*no_img;
	char	*no_addr;
	int		no_bits_per_pixel;
	int		no_line_length;
	int		no_endian;
	void	*ea_img;
	char	*ea_addr;
	int		ea_bits_per_pixel;
	int		ea_line_length;
	int		ea_endian;
	void	*so_img;
	char	*so_addr;
	int		so_bits_per_pixel;
	int		so_line_length;
	int		so_endian;
	void	*we_img;
	char	*we_addr;
	int		we_bits_per_pixel;
	int		we_line_length;
	int		we_endian;
	t_rc	*rc;
	t_map	*map;
}				t_glb;

// main
void		init_data(t_map *map, t_rc *rc);
int			check_file(char **argv, int file);
int			check_arg(int argc, char **argv);
t_rc		*parsing(t_map *map, char **argv);

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

//initialization
void		init_data(t_map *map, t_rc *rc);
void		get_e_w(t_rc *rc);
void		get_orientation_full(t_rc *rc);

// window
void		init_window(t_glb *glb);

//hooks
int			key_press(int keycode, t_glb *glb);
void		hooks(t_glb *glb);

//display
int			display(t_glb *glb);

// free00
void		freetab(char **table);
void		free_texture(t_map *map);
int			exit_parserror(t_map *map, char *err);
int			exit_parserror2(t_map *map, char *err);
int			quit(t_glb *glb);

//free01
void		free_map(t_map *map);

//raycasting
void		init_rc(t_glb *glb, int i);
void		step_sidedist(t_glb *glb);
void		dda(t_glb *glb);
void		draw_on_screen(t_glb *glb);
void		raycasting_loop(t_glb *glb);

//utils
float   	get_deltadist(float raydir);
void		pixel_put(t_glb *glb, int x, int y, int color);
int			convert_hexa_color(int red, int green, int blue);

//colors
int			get_tex_color(char *texData, int texx, int texy, int bpp);
void		get_tex(t_glb *glb);
void		get_wall(t_glb *glb, int x);
void		get_floor(t_glb *glb, int drawend, int x);
void		get_ceiling(t_glb *glb, int drawstart, int x);

//moves
void		go_forward(t_glb *glb);
void		go_backward(t_glb *glb);
void		go_left(t_glb *glb);
void		go_right(t_glb *glb);

//rotations
void		rotate_right(t_glb *glb);
void		rotate_left(t_glb *glb);

#endif
