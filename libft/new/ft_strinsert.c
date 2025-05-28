/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:50:56 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/07 17:01:37 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strinsert(char *base, char *insert, int index)
{
	char	*expand;
	int		len;
	int		i;
	int		j;
	int		exp;

	if (!base || !insert)
		return (NULL);
	len = ft_strlen(base);
	if (!(index >= 0 && index <= len))
		index = (index < 0) * 0 + (index > len) * len;
	expand = (char *)malloc(len + ft_strlen(insert) + 1);
	if (!expand)
		return (NULL);
	ft_init(3, &i, &exp, &j);
	while (i < index)
		expand[exp++] = base[i++];
	while (insert[j])
		expand[exp++] = insert[j++];
	while (base[i])
		expand[exp++] = base[i++];
	expand[exp] = '\0';
	return (expand);
}
