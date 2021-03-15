/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:39:35 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:39:37 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_len_p(t_ul n)
{
	int len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		++len;
	}
	return (len);
}

int		ft_dig_p(t_ul n, int len, char *base)
{
	int out;

	out = 0;
	if (n >= (t_ul)len)
	{
		out += ft_dig_p(n / len, len, base);
		out += ft_dig_p(n % len, len, base);
	}
	else
		out += ft_putchar(base[n]);
	return (out);
}

int		ft_putnbr_base_p(t_ul nbr)
{
	long	n;
	int		i;
	char	*base;
	int		out;

	i = 0;
	out = 0;
	n = nbr;
	base = "0123456789abcdef";
	while (base[i] != '\0')
		i++;
	out += ft_dig_p(n, i, base);
	return (out);
}

int		ft_printf_p(va_list argument, t_flags *flag)
{
	int		out;
	t_ul	a;
	int		spaces;
	int		len;

	out = 0;
	a = (t_ul)va_arg(argument, void *);
	len = int_len_p(a);
	spaces = flag->digit - len - 2;
	if (a == 0)
		spaces = flag->digit - 3;
	if (!flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(' ');
	out += ft_putstr("0x");
	out += ft_putnbr_base_p(a);
	if (flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}
