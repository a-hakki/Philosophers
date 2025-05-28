/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:17:59 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/08 10:24:12 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !to_find)
		return (NULL);
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i])
	{
		while (str[i] == to_find[j])
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
