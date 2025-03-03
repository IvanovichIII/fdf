/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:56:15 by igomez-s          #+#    #+#             */
/*   Updated: 2024/03/14 17:04:22 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cont_digitos(int nb)
{
	int	cont;

	cont = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		nb /= 10;
		cont ++;
	}
	return (cont);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		nb_t;
	int		nb_rest;
	int		cont;
	char	c[10];

	nb_t = nb;
	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		cont = cont_digitos(nb);
		while (cont > 0)
		{
			nb_rest = nb_t % 10;
			nb_t /= 10;
			if (nb > 0)
				c[cont - 1] = '0' + nb_rest;
			else
				c[cont - 1] = '0' - nb_rest;
			cont--;
		}
		if (nb < 0)
			write(fd, "-", 1);
		write (fd, c, cont_digitos(nb));
	}
}
