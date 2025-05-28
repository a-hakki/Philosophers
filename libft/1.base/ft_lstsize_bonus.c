/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:14:18 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/08 00:01:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		node_nbr;
	t_list	*tmp;

	node_nbr = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		node_nbr++;
		tmp = tmp->next;
	}
	return (node_nbr);
}
