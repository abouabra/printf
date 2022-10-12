/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:01:40 by abouabra          #+#    #+#             */
/*   Updated: 2022/10/12 16:21:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	adress_helper(unsigned long long nb, int *tracker)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		adress_helper(nb / 16, tracker);
		adress_helper(nb % 16, tracker);
	}
	else
		ft_putchar(base[nb % 16], tracker);
}

void	ft_put_adress(void *ptr, int *tracker)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	ft_putstr("0x", tracker);
	adress_helper(nb, tracker);
}

void	print_specifiers(va_list args, char str, int *tracker)
{
	if (str == 'c')
		ft_putchar(va_arg(args, int), tracker);
	if (str == '%')
		ft_putchar('%', tracker);
	if (str == 's')
		ft_putstr(va_arg(args, char *), tracker);
	if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(args, int), tracker);
	if (str == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), tracker);
	if (str == 'x')
		ft_put_hex_nbr(va_arg(args, int), 'x', tracker);
	if (str == 'X')
		ft_put_hex_nbr(va_arg(args, int), 'X', tracker);
	if (str == 'p')
		ft_put_adress(va_arg(args, void *), tracker);
}

int	ft_printf(const char *str, ...)
{
	int		tracker;
	va_list	args;

	va_start(args, str);
	tracker = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_specifiers(args, *str, &tracker);
		}
		else
		{
			ft_putchar(*str, &tracker);
		}
		str++;
	}
	va_end(args);
	return (tracker);
}
