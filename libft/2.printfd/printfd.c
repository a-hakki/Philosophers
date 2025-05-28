/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:01:30 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 01:30:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	fd_checker(int fd, int c, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, c);
	if (c == '%')
		len += fd_putchar(fd, '%');
	else if (c == 'c')
		len += fd_putchar(fd, (char)va_arg(args, int));
	else if (c == 's')
		len += fd_putstr(fd, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += fd_putnbr(fd, va_arg(args, int));
	else if (c == 'u')
		len += fd_putnbr_u(fd, va_arg(args, unsigned int));
	else if (c == 'x')
		len += fd_putnbr_x(fd, va_arg(args, int));
	else if (c == 'X')
		len += fd_putnbr_xx(fd, va_arg(args, int));
	else if (c == 'p')
		len += fd_putptr(fd, va_arg(args, void *));
	va_end(args);
	return (len);
}

int	printfd(int fd, char const *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	if (!s || fd < 0 || (write(fd, 0, 0) == -1))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				len += fd_putchar(fd, '%');
			else
				len += fd_checker(fd, s[i + 1], va_arg(args, void *));
			i += 2;
		}
		else
			len += fd_putchar(fd, s[i++]);
	}
	va_end(args);
	return (len);
}
