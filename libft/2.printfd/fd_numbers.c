/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:09 by aelsayed          #+#    #+#             */
/*   Updated: 2024/11/23 21:42:11 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	calcul(long nb)
{
	unsigned long	neg;
	int				cnt;

	cnt = 0;
	if (nb < 0)
		neg = -nb;
	else
		neg = nb;
	while (neg)
	{
		neg /= 10;
		cnt++;
	}
	if (nb < 0)
		return (cnt + 1);
	if (nb > 0)
		return (cnt);
	else
		return (TRUE);
}

int	fd_putnbr(int fd, int n)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		fd_putnbr(fd, -n);
	}
	else
	{
		fd_putnbr(fd, n / 10);
		fd_putnbr(fd, n % 10);
	}
	return (calcul(n));
}

int	fd_putnbr_u(int fd, unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	else
	{
		fd_putnbr_u(fd, n / 10);
		fd_putnbr_u(fd, n % 10);
	}
	return (calcul(n));
}

int	fd_putnbr_x(int fd, int n)
{
	char	s[9];
	int		i;
	long	nb;
	int		len;

	i = 0;
	len = 0;
	nb = (unsigned int)n;
	if (n == 0)
		return (fd_putchar(fd, '0'));
	while (nb)
	{
		s[i++] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	s[i] = '\0';
	while (i > 0)
		len += fd_putchar(fd, s[--i]);
	return (len);
}

int	fd_putnbr_xx(int fd, int n)
{
	char			s[9];
	int				i;
	unsigned int	nb;
	int				len;

	i = 0;
	len = 0;
	nb = (unsigned int)n;
	if (n == 0)
		return (fd_putchar(fd, '0'));
	while (nb)
	{
		s[i] = "0123456789ABCDEF"[nb % 16];
		nb /= 16;
		i++;
	}
	s[i] = '\0';
	while (i > 0)
		len += fd_putchar(fd, s[--i]);
	return (len);
}
