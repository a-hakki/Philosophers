/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:34:34 by aelsayed          #+#    #+#             */
/*   Updated: 2024/10/29 19:44:59 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(char const *str, int c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		i++;
		len++;
	}
	if ((char)c == '\0')
		return ((char *)(&str[i]));
	while (i--)
	{
		if (str[i] == (char)c)
			return ((char *)(&str[i]));
	}
	return ((char *)str);
}
