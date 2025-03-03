/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:30:07 by ivan              #+#    #+#             */
/*   Updated: 2025/01/23 21:34:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbru(unsigned int nbr);
int		ft_detechar(char format, va_list arg);
int		ft_printf(const char *format, ...);
int		ft_puth(unsigned int n, char *base);
int		ft_putp(size_t n, char *base);

#endif
