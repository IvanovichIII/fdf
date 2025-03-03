/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:32:17 by ivan              #+#    #+#             */
/*   Updated: 2024/04/30 17:32:24 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	unsigned int	n;

	n = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		n += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		n += ft_putnbr(nbr / 10);
		n += ft_putchar(nbr % 10 + '0');
	}
	else
		n += ft_putchar(nbr + '0');
	return (n);
}
