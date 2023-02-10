/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:28 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 12:09:41 by akusniak         ###   ########.fr       */
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


#define SPACE		' '
#define NEW_LINE	'\n'
#define YES			1
#define NO			0

#define FDF_INIT		-1
#define OPEN_F			-2
#define OPEN_E			-3
#define MALLOC_DATA		-4
#define MALLOC_DATA_BIS	-5
#define CLOSE			-6
#define READ			-7
#define MLX_CRASH		-8

#define ESC		65307
#define F		102
#define R		114
#define SPA		32
#define	LEFT	65361
#define RIGHT	65363
#define	UP		65362
#define	DOWN	65364
#define	MINUS	65453
#define	MAX		65451

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

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
    char    *map_path;
}				t_map;

typedef struct s_window
{
    size_t  hauteur;
    size_t  largeur;
}               t_window;

typedef struct s_screen
{
    t_image     image;
    t_mlx       mlx;
    t_window    window;
}               t_screen;

typedef struct  s_display
{
    int zoom;
    int position_x;
    int position_y;
    int altitude;
}               t_display;


typedef struct  s_point
{
    float   x1;
    float   y1;
    float   z1;
    float   x2;
    float   y2;
    float   z2;
    int     color;
}               t_point;

typedef struct  s_fdf
{
    t_screen    screen;
    t_map       map;
    t_display   display;
    t_point     point;
}               t_fdf;


/* DRAW.C */
int	ft_fit(t_fdf *fdf);
void	ft_line(t_fdf *fdf, int hauteur, int largeur, int which_case);
void	ft_draw(t_fdf *fdf);

/* ERRORS.C */
void    ft_errors(int error_code, t_fdf *fdf);

/* EVENTS.C */
int	ft_deal_key(int key, t_fdf *fdf);
int handle_no_event(void *data);

/* INIT.C */
void ft_create_image_env(t_fdf *fdf);
t_fdf	*ft_create_structure(char *argv);
void	ft_create_window_env(t_fdf *fdf);

/* MAP.C */
void	ft_map(t_fdf *fdf);

/* MATHS.C */
void	ft_iso(float *x, float *y, int z, int altitude);
void	ft_dda(t_fdf *fdf);

/* POINT.C */
void	ft_altitude(int *z, int altitude);
void	ft_conversion(t_fdf *fdf);
void	ft_mlx_put_pixel(t_fdf *fdf, int x, int y, int color);

/* RENDER.C */
void	ft_render(t_fdf *fdf);
void	ft_print_help(void *mlx, void *window);

/* UTILS.C */
void    ft_exit_mlx(t_fdf *fdf);
void	ft_init_map(t_fdf *fdf, char *argv);
void	ft_init_display(t_fdf *fdf);
void	ft_init_point(t_fdf *fdf);

#endif
