/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:07:45 by ivan              #+#    #+#             */
/*   Updated: 2024/03/09 23:09:48 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n-- > 0)
	{
		if (*s2 == '\0')
			return ((const unsigned char)*s1);
		if (*s1 > *s2)
			return ((const unsigned char)*s1 - (const unsigned char)*s2);
		else if (*s1 < *s2)
			return ((const unsigned char)*s1 - (const unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
