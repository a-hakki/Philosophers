/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:54:27 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 14:57:05 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (n-- && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	onlydigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '+')
		i++;
	while (str[i] && (ft_isdigit(str[i])))
		i++;
	if (!str[i])
		return (0);
	return (1);
}

int	myatoi(char *str)
{
	unsigned int	i;
	int				sign;
	long			n;

	i = 0;
	sign = 1;
	n = 0;
	if (!str || !*str || onlydigit(str) == 1 || ft_strlen(str) > 11)
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!ft_strncmp(&str[i], "2147483648", 10) || \
			!ft_strncmp(&str[i], "+2147483648", 11))
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + (str[i++] - '0');
		if (n > 2147483648)
			return (-1);
	}
	return ((n != 0) * sign * n + (n == 0) * -1);
}
