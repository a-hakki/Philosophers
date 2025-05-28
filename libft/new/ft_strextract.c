/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:59:31 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/11 22:59:39 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strextract(char *str, int index, char sep)
{
	int	start;
	int	end;

	if (!str || index < 0 || index >= (int)ft_strlen(str))
		return (NULL);
	start = index;
	end = index;
	while (start > 0 && str[start - 1] != sep)
		start--;
	while (str[end] && str[end] != sep)
		end++;
	return (ft_substr(str, start, end - start));
}
