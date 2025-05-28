/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:24:44 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/10 11:10:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_insert_char(char *str, int index, char c)
{
	char	*new_str;

	int (len), (i), (j);
	if (!str || index < 0 || index > (int)ft_strlen(str))
		return (NULL);
	len = ft_strlen(str);
	new_str = (char *)malloc(len + 2);
	if (!new_str)
		return (NULL);
	ft_init(2, &i, &j);
	while (i < len + 1)
	{
		if (i == index)
			new_str[i] = c;
		else
			new_str[i] = str[j++];
		i++;
	}
	new_str[len + 1] = '\0';
	free(str);
	return (new_str);
}
