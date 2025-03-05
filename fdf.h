/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:18:14 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/04 20:05:42 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define ANG 0.8
#ifndef NO_ERROR
#define NO_ERROR 0
#endif

typedef struct s_fdf
{
	mlx_t		*mlx;
	char		**argv;
	int			**map;
	int			fil;
	int			col;
	int			zoom;
	float		ang;
	mlx_image_t	*g_img;
	int			width;
	int			height;
} t_fdf;

#endif