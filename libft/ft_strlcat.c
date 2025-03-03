/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:41:44 by ivan              #+#    #+#             */
/*   Updated: 2024/03/11 16:00:42 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	while (*s1 != '\0')
	{
		s1++;
		i++;
	}
	dlen = i;
	slen = ft_strlen(s2);
	if (n == 0 || n <= dlen)
		return (slen + n);
	i = 0;
	while (*s2 != '\0' && i < n - dlen - 1)
	{
		*s1 = *s2;
		s1++;
		s2++;
		i++;
	}
	*s1 = '\0';
	return (slen + dlen);
}
