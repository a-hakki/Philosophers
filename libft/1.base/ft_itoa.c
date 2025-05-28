/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:28:29 by aelsayed          #+#    #+#             */
/*   Updated: 2024/10/28 13:14:41 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	calcul(int nb)
{
	unsigned int	negative;
	int				cnt;

	cnt = 0;
	if (nb < 0)
		negative = -nb;
	else
		negative = nb;
	while (negative)
	{
		negative /= 10;
		cnt++;
	}
	if (nb < 0)
		return (cnt + 2);
	if (nb > 0)
		return (cnt + 1);
	else
		return (2);
}

char	*ft_itoa(int nb)
{
	char	*arr;
	int		i;
	long	n;

	n = nb;
	i = calcul(nb);
	if (nb < 0)
		n = -n;
	arr = (char *)malloc(i);
	if (!arr)
		return (NULL);
	arr[i - 1] = '\0';
	while (n)
	{
		i--;
		arr[i - 1] = (n % 10) + 48;
		n = n / 10;
	}
	if (nb < 0)
		arr[0] = '-';
	if (nb == 0)
		arr[0] = 48;
	return (arr);
}
