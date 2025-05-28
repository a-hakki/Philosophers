/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:10:57 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/18 18:11:34 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstdup(t_list *head)
{
	t_list	*new;
	t_list	*lst;

	new = NULL;
	lst = head;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(lst->content)));
		lst = lst->next;
	}
	return (new);
}
