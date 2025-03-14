/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:08:56 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 14:16:58 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	print_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->fil)
	{
		j = 0;
		while (j < fdf->col)
		{
			ft_printf("%d ", fdf->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	put_pix(t_fdf *fdf, int x, int y, int color)
{
	mlx_put_pixel(fdf->g_img, x, y, color);
}

int	ft_wordcount(char *line)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (i);
}

int	get_col(t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(fdf->argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = ft_wordcount(line);
	free(line);
	close(fd);
	return (i);
}
