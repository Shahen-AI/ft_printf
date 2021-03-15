/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:39:22 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:39:29 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_flag(int zeros, t_flags *flag, int zero, int spaces)
{
	int out;

	out = 0;
	if (flag->zero && flag->dot == -1)
		zero = '0';
	if (!flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(zero);
	while (zeros--)
		out += ft_putchar('0');
	return (out);
}

int		ft_x_zero(int out, t_flags *flag)
{
	if ((flag->dot != 0 && flag->digit) || (flag->dot && !flag->digit))
		out += ft_putchar('0');
	else if (!flag->digit && flag->dot == 0)
		return (out);
	else
		out += ft_putchar(' ');
	return (out);
}

int		ft_dig(long n, int len, char *base)
{
	int out;

	out = 0;
	if (n < 0)
		out += ft_dig(n * (-1), len, base);
	if (n >= len)
	{
		out += ft_dig(n / len, len, base);
		out += ft_dig(n % len, len, base);
	}
	else
		out += ft_putchar(base[n]);
	return (out);
}

int		ft_putnbr_base_x(unsigned int nbr, char format)
{
	long	n;
	int		i;
	char	*base;
	int		out;

	i = 0;
	out = 0;
	n = nbr;
	base = (format == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	while (base[i] != '\0')
		i++;
	out += ft_dig(n, i, base);
	return (out);
}

int		ft_printf_hex(va_list argument, t_flags *flag, char format)
{
	int				out;
	unsigned int	a;
	int				spaces;
	int				zeros;
	char			zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, unsigned int);
	zeros = (flag->dot - int_len_x(a) < 0 ? 0 : flag->dot - int_len_x(a));
	spaces = flag->digit - int_len_x(a) - zeros;
	out += ft_hex_flag(zeros, flag, zero, spaces);
	if (a < 0)
		out += ft_putnbr_base_x(4294967295 + a, format);
	if (a > 0 || flag->dot != 0)
		out += ft_putnbr_base_x(a, format);
	else if (a == 0)
		out = ft_x_zero(out, flag);
	else
		out += ft_putchar(zero);
	if (flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}
