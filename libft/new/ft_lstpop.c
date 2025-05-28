/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:51:34 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/06 21:51:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstpop(t_list *node, size_t n)
{
	t_list	*head;
	t_list	*tmp;

	if (!node || !node->next)
		return ;
	head = node;
	node = node->next;
	tmp = NULL;
	while (node && n--)
	{
		tmp = node->next;
		free(node->content);
		free(node);
		node = tmp;
	}
	head->next = node;
}
