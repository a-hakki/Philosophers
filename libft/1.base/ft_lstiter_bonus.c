/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:25:23 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/24 12:45:29 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, int (*f)(char const *, ...))
{
	if (lst && f)
	{
		while (lst)
		{
			f("%s$\n", (char *)lst->content);
			lst = lst->next;
		}
	}
}
