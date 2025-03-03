/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:20 by ivan              #+#    #+#             */
/*   Updated: 2024/04/30 17:33:24 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(size_t n, char *base)
{
	size_t	nbr_final[16];
	int		result;
	int		i;

	i = 0;
	result = 0;
	if (n == 0)
		result += write(1, "0x0", 3);
	if (n != 0)
		result += write(1, "0x", 2);
	while (n)
	{
		nbr_final[i] = n % 16;
		n = n / 16;
		i++;
	}
	while (--i >= 0)
		result += ft_putchar(base[nbr_final[i]]);
	return (result);
}
