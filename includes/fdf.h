/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:28 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/13 10:40:14 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>

# include <X11/X.h>
# include <X11/keysym.h>

# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"

# define SPACE ' '
# define NEW_LINE '\n'
# define YES 1
# define NO 0
# define WIN_CRASH -1
# define MLX_CRASH -2
# define ESC 65307
# define F 102
# define R 114
# define SPA 32
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define MINUS 65453
# define MAX 65451
# define BLUE 0x0000FF
# define NAVY_BLUE 0x000080
# define GREEN 0x006400
# define MARRON 0x8B4513

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}			t_mlx;

typedef struct s_map
{
	int		hauteur;
	int		largeur;
	int		**data;
	char	*map_path;
	int		max_altitude;
}			t_map;

typedef struct s_window
{
	size_t	hauteur;
	size_t	largeur;
}			t_window;

typedef struct s_screen
{
	t_image		image;
	t_mlx		mlx;
	t_window	window;
}			t_screen;

typedef struct s_display
{
	int		zoom;
	int		position_x;
	int		position_y;
	float	altitude;
}			t_display;

typedef struct s_point
{
	float	x1;
	float	y1;
	float	z1;
	float	x2;
	float	y2;
	float	z2;
	int		color;
}			t_point;

typedef struct s_fdf
{
	t_screen	screen;
	t_map		map;
	t_display	display;
	t_point		point;
}			t_fdf;

int		ft_fit(t_fdf *fdf);
void	ft_line(t_fdf *fdf, int hauteur, int largeur, int which_case);
void	ft_draw(t_fdf *fdf);
void	ft_errors(int error_code, t_fdf *fdf);
int		ft_deal_key(int key, t_fdf *fdf);
int		handle_no_event(void *data);
void	ft_create_image_env(t_fdf *fdf);
t_fdf	*ft_create_structure(char *argv);
void	ft_create_window_env(t_fdf *fdf);
void	ft_map(t_fdf *fdf);
void	ft_iso(float *x, float *y, float z, float altitude);
void	ft_dda(t_fdf *fdf);
void	ft_altitude(float *z, float altitude);
void	ft_conversion(t_fdf *fdf);
void	ft_mlx_put_pixel(t_fdf *fdf, int x, int y, int color);
void	ft_render(t_fdf *fdf);
void	ft_print_help(void *mlx, void *window);
void	ft_exit_mlx(t_fdf *fdf);
void	ft_init_map(t_fdf *fdf, char *argv);
void	ft_init_display(t_fdf *fdf);
void	ft_init_point(t_fdf *fdf);
void	ft_color(float z1, int *color, int max_altitude);
void	ft_draw_rect(t_fdf *fdf);
int		main(int argc, char **file);

#endif
