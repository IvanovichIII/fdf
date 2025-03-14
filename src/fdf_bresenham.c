/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:08:38 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 14:44:44 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bresenham(t_bresenham *b, int *puntos)
{
	b->dx = abs(puntos[2] - puntos[0]);
	b->dy = abs(puntos[3] - puntos[1]);
	if (puntos[0] < puntos[2])
		b->sx = 1;
	else
		b->sx = -1;
	if (puntos[1] < puntos[3])
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
}

void	bresenham(t_fdf *fdf, int *puntos, int color)
{
	t_bresenham	b;
	int			e2;

	init_bresenham(&b, puntos);
	while (1)
	{
		put_pix(fdf, puntos[0], puntos[1], color);
		if (puntos[0] == puntos[2] && puntos[1] == puntos[3])
			break ;
		e2 = b.err * 2;
		if (e2 > -b.dy)
		{
			b.err -= b.dy;
			puntos[0] += b.sx;
		}
		if (e2 < b.dx)
		{
			b.err += b.dx;
			puntos[1] += b.sy;
		}
	}
}
