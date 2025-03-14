/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:44:21 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 15:03:07 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int *x, int *y, int z, t_fdf *fdf)
{
	int	prev_x;
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(fdf->ang_z) + z * sin(fdf->ang_z);
	z = -prev_y * sin(fdf->ang_z) + z * cos(fdf->ang_z);
	prev_x = *x;
	*x = prev_x * cos(fdf->ang_z) + z * sin(fdf->ang_z);
	z = -prev_x * sin(fdf->ang_z) + z * cos(fdf->ang_z);
	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(fdf->ang_z) - prev_y * sin(fdf->ang_z);
	*y = prev_x * sin(fdf->ang_z) + prev_y * cos(fdf->ang_z);
}

void	dale_duro(void *param)
{
	t_fdf	*fdf;
	int		puntos[4];
	int		i;
	int		j;

	fdf = param;
	i = 0;
	while (i < fdf->fil - 1)
	{
		j = 0;
		while (j < fdf->col - 1)
		{
			draw_rigth(fdf, puntos, i, j);
			draw_down(fdf, puntos, i, j);
			j++;
		}
		i++;
	}
}

void	init_fdf(t_fdf *fdf)
{
	fdf->zoom = 1;
	fdf->modo = 0;
	fdf->ang = ANG;
	fdf->ang_z = 0;
	fdf->color_p = 10;
	fdf->color_s = 2;
	fdf->width = fmax(100,
			fabs((fdf->col + fdf->fil) * fdf->zoom * cos(fdf->ang)));
	fdf->height = fmax(100,
			fabs((fdf->col + fdf->fil) * fdf->zoom * sin(fdf->ang) * 0.8));
	fdf->mlx = mlx_init(fdf->width, fdf->height, "Fdf by igomez-s", true);
	fdf->g_img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	mlx_key_hook(fdf->mlx, &check_keypress, (void *)fdf);
	mlx_image_to_window(fdf->mlx, fdf->g_img, 0, 0);
	mlx_scroll_hook(fdf->mlx, &my_scrollhook, fdf);
	mlx_loop_hook(fdf->mlx, &dale_duro, (void *)fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (argv)
		fdf->argv = argv;
	fdf->fil = get_fil(fdf);
	fdf->col = get_col(fdf);
	get_map(fdf);
	init_fdf(fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free(fdf);
	return (0);
}
