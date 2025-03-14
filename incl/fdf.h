/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:18:14 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 14:42:36 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 512
# define HEIGHT 512
# define ANG 0.8
# ifndef NO_ERROR
#  define NO_ERROR 0
# endif

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	char		**argv;
	int			**map;
	int			fil;
	int			col;
	int			color_p;
	int			color_s;
	int			color_t;
	int			zoom;
	int			ver_move;
	int			hor_move;
	int			x_mouse;
	int			y_mouse;
	int			modo;
	float		ang;
	float		ang_z;
	int			width;
	int			height;
}	t_fdf;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

int		get_rgba(int r, int g, int b, int a);
void	print_map(t_fdf *fdf);
void	put_pix(t_fdf *fdf, int x, int y, int color);
void	rotate(int *x, int *y, int z, t_fdf *fdf);
void	init_bresenham(t_bresenham *b, int *puntos);
void	bresenham(t_fdf *fdf, int *puntos, int color);
void	draw_rigth3(t_fdf *fdf, int puntos[4], int i, int j);
void	draw_rigth2(t_fdf *fdf, int puntos[4], int i, int j);
void	draw_rigth(t_fdf *fdf, int puntos[4], int i, int j);
void	draw_down3(t_fdf *fdf, int puntos[4], int i, int j);
void	draw_down2(t_fdf *fdf, int puntos[4], int i, int j);
void	draw_down(t_fdf *fdf, int puntos[4], int i, int j);
void	dale_duro(void *param);
void	fill_map(t_fdf *fdf, char *line, int fil);
void	get_map(t_fdf *fdf);
int		get_fil(t_fdf *fdf);
int		ft_wordcount(char *line);
int		get_col(t_fdf *fdf);
void	clear_content(t_fdf *fdf);
void	keypress_r(mlx_key_data_t key, t_fdf *fdf);
void	keypress_move(mlx_key_data_t key, t_fdf *fdf);
void	check_keypress(mlx_key_data_t key, void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);
void	init_fdf(t_fdf *fdf);

#endif