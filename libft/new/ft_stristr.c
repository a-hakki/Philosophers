/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:57:45 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/21 10:59:06 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stristr(char const *str, char const *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !to_find)
		return (-1);
	if (to_find[i] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return (i);
		}
		i = i - j;
		i++;
		j = 0;
	}
	return (-1);
}
