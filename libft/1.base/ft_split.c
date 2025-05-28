/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:30:44 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:30:02 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	allocator(char const *s, int row, char b)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i] == b)
		i++;
	while (row--)
	{
		while (s[i] != b)
			i++;
		while (s[i] == b && s[i])
			i++;
	}
	while (s[i] != b && s[i])
	{
		len++;
		i++;
	}
	return (len + 1);
}

static int	words(char const *s, char b)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	if (b == '\0')
		return (TRUE);
	while (s[i] == b)
		i++;
	while (s[i])
	{
		cnt++;
		while (s[i] != b && s[i])
			i++;
		while (s[i] == b)
			i++;
	}
	return (cnt);
}

static char	*stricpy(char *dest, char const *src, char b, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j] == b)
		j++;
	while (index--)
	{
		while (src[j] != b && src[j])
			j++;
		while (src[j] == b)
			j++;
	}
	while (src[j] != b && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

static char	**check_free(char **arr, int i)
{
	if (!arr)
		return (NULL);
	while (i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i--;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char	**ft_split(char const *s, char b)
{
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (words(s, b) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words(s, b))
	{
		arr[i] = (char *)malloc(allocator(s, i, b));
		if (!arr[i])
			return (check_free(arr, i));
		i++;
	}
	i = 0;
	while (i < words(s, b))
	{
		arr[i] = stricpy(arr[i], s, b, i);
		i++;
	}
	arr[words(s, b)] = NULL;
	return (arr);
}
