/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:27:13 by aelsayed          #+#    #+#             */
/*   Updated: 2024/10/25 15:46:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*byte;
	void			*mem;
	size_t			i;

	i = 0;
	mem = (void *)malloc(count * size);
	if (!mem)
		return (NULL);
	byte = (unsigned char *)mem;
	while (i < count * size)
		byte[i++] = 0;
	return (mem);
}
