/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:22:36 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/12 07:36:20 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// function that expects only the address of an integer or a character
void	ft_init(int count, ...)
{
	va_list	args;
	int		i;
	int		*ptr;

	i = 0;
	va_start(args, count);
	while (i < count)
	{
		ptr = va_arg(args, int *);
		*ptr = 0;
		i++;
	}
	va_end(args);
}
