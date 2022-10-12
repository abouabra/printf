/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:18:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/10/12 16:24:38 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

void	ft_putchar(char c, int *tracker);
void	ft_putnbr(int n, int *tracker);
void	ft_putstr(char *s, int *tracker);
void	ft_put_unsigned_nbr(unsigned int nb, int *tracker);
void	ft_put_hex_nbr(unsigned int nb, char x, int *tracker);
void	ft_put_adress(void *ptr, int *tracker);

#endif
