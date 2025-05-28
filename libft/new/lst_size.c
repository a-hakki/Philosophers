/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:18:49 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:28:42 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	lst_size(t_lst *lst)
{
	int		node_nbr;
	t_lst	*tmp;

	node_nbr = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		node_nbr++;
		tmp = tmp->next;
	}
	return (node_nbr);
}
