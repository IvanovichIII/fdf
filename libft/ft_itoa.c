/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:54:22 by ivan              #+#    #+#             */
/*   Updated: 2024/03/15 12:58:30 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numlen(int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*num;
	unsigned int	nb;

	len = ft_numlen(n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb == 0)
		num[0] = '0';
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = '0' + (nb % 10);
		nb = nb / 10;
		len--;
	}
	return (num);
}
