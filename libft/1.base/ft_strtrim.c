/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:23:17 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:40:51 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	if (!s || !set)
		return (NULL);
	if (*s == '\0')
		return ((char *)ft_calloc(1, 1));
	while (s[end])
		end++;
	end--;
	while (ft_strchr(set, s[start]) && s[start])
		start++;
	while (ft_strchr(set, s[end]) && end)
		end--;
	return (ft_substr(s, start, end - start + 1));
}
