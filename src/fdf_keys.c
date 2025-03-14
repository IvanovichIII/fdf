/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:08:47 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 15:04:59 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_content(t_fdf *fdf)
{
	fdf->width = fmax(100, fabs((fdf->col + fdf->fil)
				* fdf->zoom * cos(fdf->ang)));
	fdf->height = fmax(100, fabs((fdf->col + fdf->fil)
				* fdf->zoom * sin(fdf->ang) * 0.8));
	mlx_delete_image(fdf->mlx, fdf->g_img);
	fdf->g_img = mlx_new_image(fdf->mlx, fdf->width + 1, fdf->height + 1);
	mlx_image_to_window(fdf->mlx, fdf->g_img, 0, 0);
}

void	keypress_r(mlx_key_data_t key, t_fdf *fdf)
{
	if (key.key == MLX_KEY_R && key.action == MLX_PRESS)
	{
		fdf->modo = 0;
		fdf->ang = ANG;
		fdf->ang_z = 0;
		fdf->ver_move = 0;
		fdf->hor_move = 0;
		fdf->color_p = 10;
		fdf->color_s = 2;
		fdf->color_t = 0;
	}
}

void	keypress_move(mlx_key_data_t key, t_fdf *fdf)
{
	if (key.key == MLX_KEY_UP
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		fdf->ver_move -= 1 * fdf->zoom;
	if (key.key == MLX_KEY_DOWN
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		fdf->ver_move += 1 * fdf->zoom;
	if (key.key == MLX_KEY_RIGHT
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		fdf->hor_move += 1 * fdf->zoom;
	if (key.key == MLX_KEY_LEFT
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		fdf->hor_move -= 1 * fdf->zoom;
	if (key.key == MLX_KEY_Q
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		fdf->ang_z += 0.1 * fdf->zoom;
	if (key.key == MLX_KEY_E
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		fdf->ang_z -= 0.1 * fdf->zoom;
}

void	check_keypress(mlx_key_data_t key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
	keypress_move(key, fdf);
	keypress_r(key, fdf);
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
	{
		if (fdf->modo >= 3)
			fdf->modo = 0;
		else
			fdf->modo++;
		fdf->hor_move = 0;
		fdf->ver_move = 0;
	}
	if (key.key == MLX_KEY_C
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
	{
		fdf->color_p += 7;
		fdf->color_s += 3;
		fdf->color_t += 1;
	}
	clear_content(fdf);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (ydelta > 0 && fdf->width < 5000)
	{
		fdf->zoom++;
	}
	else if (ydelta < 0 && fdf->zoom > 1)
	{
		fdf->zoom--;
	}
	clear_content(fdf);
}
