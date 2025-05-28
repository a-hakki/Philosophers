/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:56:11 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/24 15:23:33 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strpbrk(char const *str, char *set)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return ((char *)(&str[i]));
		i++;
	}
	if (ft_strchr(set, '\0'))
		return ((char *)(&str[i]));
	else
		return (NULL);
}
