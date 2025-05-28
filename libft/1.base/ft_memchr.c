/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:29:28 by aelsayed          #+#    #+#             */
/*   Updated: 2024/10/22 12:29:33 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(void const *s, int ch, size_t n)
{
	unsigned char const	*src;

	src = (unsigned char const *)s;
	if (!s)
		return (NULL);
	while (n--)
	{
		if (*src == (unsigned char)ch)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
