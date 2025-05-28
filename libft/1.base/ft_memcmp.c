/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:29:43 by aelsayed          #+#    #+#             */
/*   Updated: 2024/11/03 22:30:58 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(void const *str1, void const *str2, size_t n)
{
	unsigned char const	*s1;
	unsigned char const	*s2;

	s1 = (unsigned char const *)str1;
	s2 = (unsigned char const *)str2;
	if (!str1 || !str2)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
