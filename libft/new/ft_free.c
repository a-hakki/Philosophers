/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:02:25 by aelsayed          #+#    #+#             */
/*   Updated: 2025/04/07 16:24:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	free1(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

static void	free2(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free1(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

static void	free3(char ***spl)
{
	int	i;

	i = 0;
	if (!spl)
		return ;
	while (spl[i])
	{
		free2(spl[i]);
		i++;
	}
	free(spl);
	spl = NULL;
}

char	*ft_free(char *format, ...)
{
	va_list	fre;
	int		i;

	i = 0;
	va_start(fre, format);
	while (format[i])
	{
		if (format[i] == '1')
			free1(va_arg(fre, char *));
		if (format[i] == '2')
			free2(va_arg(fre, char **));
		if (format[i] == '3')
			free3(va_arg(fre, char ***));
		i++;
	}
	va_end(fre);
	return (NULL);
}
