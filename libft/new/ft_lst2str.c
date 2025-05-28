/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:44:46 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/11 23:25:35 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lst2str(t_list *node)
{
	int		total_len;
	char	*str;
	t_list	*curr;

	total_len = 0;
	curr = node;
	while (curr)
	{
		if (curr->content)
			total_len += ft_strlen((char *)curr->content);
		curr = curr->next;
	}
	str = (char *)malloc(total_len + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	while (node)
	{
		if (node->content)
			ft_strlcat(str, (char *)node->content, total_len + 1);
		node = node->next;
	}
	return (str);
}
