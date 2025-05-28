/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:42:19 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/26 00:41:01 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstgetnode(t_list *lst, size_t pos)
{
	if (pos <= 0)
		return (lst);
	while (lst && lst->next && pos--)
		lst = lst->next;
	return (lst);
}
