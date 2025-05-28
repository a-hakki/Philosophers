/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:30:11 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:48:26 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char const	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (unsigned char const *)src;
	i = 0;
	if (!dest || !src)
		return (NULL);
	if (d < s || d >= s + n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d != s)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
