/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:09:01 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/14 14:17:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(t_fdf *fdf, char *line, int fil)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
	{
		fdf->map[fil][i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

void	get_map(t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		i;

	fdf->map = (int **)malloc(sizeof(int *) * (fdf->fil + 1));
	i = 0;
	while (i <= fdf->fil)
		fdf->map[i++] = (int *)malloc(sizeof(int) * (fdf->col + 1));
	fd = open(fdf->argv[1], O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_map(fdf, line, i);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	get_fil(t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(fdf->argv[1], O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}
