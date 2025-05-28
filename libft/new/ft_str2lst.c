/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:47:37 by aelsayed          #+#    #+#             */
/*   Updated: 2025/05/06 21:49:20 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_str2lst(char *str)
{
	int		i;
	t_list	*node;

	i = 0;
	node = NULL;
	while (str && str[i])
		ft_lstadd_back(&node, ft_lstnew(ft_strndup(&str[i++], 1)));
	return (node);
}
