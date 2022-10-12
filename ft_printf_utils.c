/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/10/12 16:21:20 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *tracker)
{
	write(1, &c, 1);
	(*tracker)++;
}

void	ft_putnbr(int n, int *tracker)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-', tracker);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, tracker);
		ft_putnbr(nb % 10, tracker);
	}
	else
		ft_putchar(nb + '0', tracker);
}

void	ft_putstr(char *s, int *tracker)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i], tracker);
		i++;
	}
}

void	ft_put_unsigned_nbr(unsigned int nb, int *tracker)
{
	if (nb >= 10)
	{
		ft_put_unsigned_nbr(nb / 10, tracker);
		ft_put_unsigned_nbr(nb % 10, tracker);
	}
	else
		ft_putchar(nb + '0', tracker);
}

void	ft_put_hex_nbr(unsigned int nb, char x, int *tracker)
{
	char	*base;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_put_hex_nbr(nb / 16, x, tracker);
		ft_put_hex_nbr(nb % 16, x, tracker);
	}
	else
		ft_putchar(base[nb % 16], tracker);
}
