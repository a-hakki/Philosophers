/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:01:48 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/18 18:10:34 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstndup(t_list *head, t_list *stop)
{
	t_list	*new;
	t_list	*lst;

	new = NULL;
	lst = head;
	while (lst && lst != stop)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(lst->content)));
		lst = lst->next;
	}
	return (new);
}
