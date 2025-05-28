/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:34:24 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:40:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !to_find || !len)
		return (NULL);
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (str[i] == to_find[j] && i < len)
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i - j]);
		}
		i = i - j;
		i++;
		j = 0;
	}
	return (NULL);
}
