/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:53:58 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/06 21:58:14 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstinsert(t_list *pos, t_list *insert)
{
	t_list	*last;
	t_list	*next;

	if (!insert)
		return ;
	if (!pos)
		pos = insert;
	next = pos->next;
	pos->next = insert;
	last = ft_lstlast(insert);
	if (last)
		last->next = next;
}
