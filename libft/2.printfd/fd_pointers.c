/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:28:35 by aelsayed          #+#    #+#             */
/*   Updated: 2024/11/23 21:48:08 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	fd_putchar(int fd, char c)
{
	write (fd, &c, 1);
	return (1);
}

int	fd_putstr(int fd, char const *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	fd_putnbr_adr(int fd, unsigned long n)
{
	char			s[20];
	int				i;
	unsigned long	nb;
	int				len;

	i = 0;
	len = 0;
	nb = n;
	while (nb)
	{
		s[i] = "0123456789abcdef"[nb % 16];
		nb /= 16;
		i++;
	}
	s[i] = '\0';
	while (i > 0)
		len += fd_putchar(fd, s[--i]);
	return (len);
}

int	fd_putptr(int fd, void *ptr)
{
	int				len;
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
		len = fd_putstr(fd, "(nil)");
	else
	{
		len = fd_putstr(fd, "0x");
		len += fd_putnbr_adr(fd, address);
	}
	return (len);
}
