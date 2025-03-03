/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:30:20 by ivan              #+#    #+#             */
/*   Updated: 2024/04/30 17:30:49 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_detechar(char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_putp(va_arg(arg, size_t), "0123456789abcdef"));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putnbru(va_arg(arg, unsigned int)));
	else if (format == 'x')
		return (ft_puth(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_puth(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		result;

	va_start(arg, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
			result += ft_detechar(*(++format), arg);
		else
			result += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (result);
}
