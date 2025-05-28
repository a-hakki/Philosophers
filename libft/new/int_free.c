/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:05:42 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:28:42 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	free1(int *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

static void	free2(int **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	*int_free(char *format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '1')
			free1(va_arg(arg, int *));
		if (format[i] == '2')
			free2(va_arg(arg, int **));
		i++;
	}
	va_end(arg);
	return (NULL);
}
