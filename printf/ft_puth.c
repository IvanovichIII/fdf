/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:31:58 by ivan              #+#    #+#             */
/*   Updated: 2024/04/30 17:32:07 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puth(unsigned int n, char *base)
{
	int	nbr_final[16];
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (n == 0)
		result += ft_putchar('0');
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
