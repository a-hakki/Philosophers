/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:22:20 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:28:42 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*alloc1(int len)
{
	char	*str;

	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static char	**alloc2(int wd, int len)
{
	char	**arr;
	int		i;

	arr = (char **)malloc((wd + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < wd)
	{
		arr[i] = alloc1(len);
		if (!arr[i])
			return (NULL);
		i++;
	}
	arr[wd] = NULL;
	return (arr);
}

t_alloc	*ft_malloc(char *format, int len, int wd, int slen)
{
	t_alloc	all;
	t_alloc	*a;
	int		i;

	a = &all;
	i = 0;
	while (format[i])
	{
		if (format[i] == '1')
			all.s = alloc1(len);
		if (format[i] == '2')
			all.arr = alloc2(wd, slen);
		if (!all.s || !all.arr)
			return (NULL);
		i++;
	}
	return (a);
}
