/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_write_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:09:14 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 14:14:56 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rigth3(t_fdf *fdf, int puntos[4], int i, int j)
{
	if (fdf->modo == 2)
	{
		puntos[0] = ((j - i) * fdf->zoom)
			/ (1 + (fdf->map[i][j] * 0.005)) / 2;
		puntos[1] = ((j + i) * fdf->zoom - fdf->map[i][j] * 2)
			/ (1 + (fdf->map[i][j] * 0.005)) / 2;
		puntos[2] = (((j + 1) - i) * fdf->zoom)
			/ (1 + (fdf->map[i][j + 1] * 0.005)) / 2;
		puntos[3] = (((j + 1) + i) * fdf->zoom - fdf->map[i][j + 1] * 2)
			/ (1 + (fdf->map[i][j + 1] * 0.005)) / 2;
		puntos[0] += fdf->width / 2 + fdf->hor_move;
		puntos[1] += fdf->height / 10 + fdf->ver_move;
		puntos[2] += fdf->width / 2 + fdf->hor_move;
		puntos[3] += fdf->height / 10 + fdf->ver_move;
	}
}

void	draw_rigth2(t_fdf *fdf, int puntos[4], int i, int j)
{
	if (fdf->modo == 0)
	{
		puntos[0] = (puntos[0] - puntos[1]) * cos(fdf->ang);
		puntos[1] = (puntos[0] + puntos[1]) * sin(fdf->ang) - fdf->map[i][j];
		puntos[2] = (puntos[2] - puntos[3]) * cos(fdf->ang);
		puntos[3] = (puntos[2] + puntos[3]) * sin(fdf->ang)
			- fdf->map[i][j + 1];
		puntos[0] += fdf->width / 2 + fdf->hor_move;
		puntos[1] += fdf->height / 5 + fdf->ver_move;
		puntos[2] += fdf->width / 2 + fdf->hor_move;
		puntos[3] += fdf->height / 5 + fdf->ver_move;
	}
	else if (fdf->modo == 1)
	{
		puntos[0] = (j * fdf->zoom) + (fdf->map[i][j] * 0.5);
		puntos[1] = (i * fdf->zoom) - (fdf->map[i][j] * 0.5);
		puntos[2] = ((j + 1) * fdf->zoom) + (fdf->map[i][j + 1] * 0.5);
		puntos[3] = (i * fdf->zoom) - (fdf->map[i][j + 1] * 0.5);
		puntos[0] += fdf->width / 10 + fdf->hor_move;
		puntos[1] += fdf->height / 10 + fdf->ver_move;
		puntos[2] += fdf->width / 10 + fdf->hor_move;
		puntos[3] += fdf->height / 10 + fdf->ver_move;
	}
}

void	draw_rigth(t_fdf *fdf, int puntos[4], int i, int j)
{
	puntos[0] = j * fdf->zoom;
	puntos[1] = i * fdf->zoom;
	puntos[2] = j * fdf->zoom + fdf->zoom;
	puntos[3] = i * fdf->zoom;
	draw_rigth2(fdf, puntos, i, j);
	draw_rigth3(fdf, puntos, i, j);
	rotate(&puntos[0], &puntos[1], fdf->map[i][j], fdf);
	rotate(&puntos[2], &puntos[3], fdf->map[i][j + 1], fdf);
	if ((puntos[1] > 0 && puntos[3] > 0)
		&& (puntos[1] < fdf->height && puntos[3] < fdf->height))
		if (j < fdf->col - 1 && i < fdf->fil - 1)
			if (fdf->map[i][j] >= 0)
				bresenham(fdf, puntos, get_rgba(fdf->map[i][j] * fdf->color_p,
						fdf->map[i][j] * fdf->color_s,
						fdf->map[i][j] * fdf->color_t, 255));
	else if (fdf->map[i][j] < 0)
		bresenham(fdf, puntos, get_rgba(fdf->map[i][j] * fdf->color_t,
				fdf->map[i][j] * fdf->color_s,
				fdf->map[i][j] * fdf->color_p, 255));
}
