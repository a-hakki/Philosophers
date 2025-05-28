/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:26:09 by aelsayed          #+#    #+#             */
/*   Updated: 2024/11/04 16:10:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(char const *str)
{
	unsigned int	i;
	int				sign;
	long			n;

	sign = 1;
	ft_init(2, &i, &n);
	while (ft_strchr(WHITE, str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (sign == 1 && (n > (LONG_MAX - (str[i] - '0')) / 10))
			return (-1);
		if (sign == -1 && (n < (LONG_MIN + (str[i] - '0')) / 10))
			return (0);
		n = n * 10 + (str[i++] - '0');
	}
	return (n * sign);
}
