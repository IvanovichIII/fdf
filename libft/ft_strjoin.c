/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:06:34 by ivan              #+#    #+#             */
/*   Updated: 2024/03/14 01:14:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	char	*or_ptr;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	or_ptr = ptr;
	ft_strlcpy(ptr, s1, s1len + 1);
	ft_strlcpy(ptr + s1len, s2, s2len + 1);
	return (or_ptr);
}
