/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:51:02 by igomez-s          #+#    #+#             */
/*   Updated: 2024/03/12 09:04:06 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;
	char	*or_ptr;

	i = ft_strlen(str);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	or_ptr = ptr;
	if (ptr != NULL)
	{
		while (*str)
			*ptr++ = *str++;
		*ptr = '\0';
	}
	return (or_ptr);
}
