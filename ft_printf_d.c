/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:39:10 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:39:12 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d_flag(int a, t_flags *flag, int zero, int spaces)
{
	int out;

	out = 0;
	if (flag->zero && flag->dot == -1)
		zero = '0';
	if ((a < 0 && zero == '0'))
	{
		out += ft_putchar('-');
		a = -a;
	}
	if (!flag->minus && spaces > 0)
		while (spaces--)
			out += ft_putchar(zero);
	if (a < 0 && zero == ' ')
	{
		out += ft_putchar('-');
		a = -a;
	}
	return (out);
}

int	ft_d_zero(int out, t_flags *flag)
{
	if ((flag->dot != 0 && flag->digit) || (flag->dot && !flag->digit))
		out += ft_putchar('0');
	else if (!flag->digit && flag->dot == 0)
		return (out);
	else
		out += ft_putchar(' ');
	return (out);
}

int	ft_printf_d(va_list argument, t_flags *flag)
{
	int		out;
	int		spaces;
	int		a;
	int		zeros;
	char	zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, int);
	zeros = (flag->dot - int_len(a) < 0 ? 0 : flag->dot - int_len(a));
	spaces = flag->digit - int_len(a) - zeros;
	if (a < 0)
		--spaces;
	out += ft_d_flag(a, flag, zero, spaces);
	while (zeros--)
		out += ft_putchar('0');
	if (a != 0)
		out = ft_d_out(a, out);
	else
		out = ft_d_zero(out, flag);
	if (flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}

int	ft_d_out(int a, int out)
{
	char *str;

	str = ft_itoa(a);
	out += ft_putstr(str);
	free(str);
	return (out);
}

int	int_len_x(int n)
{
	int len;

	len = 0;
	if (n < 0)
		return (8);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		++len;
	}
	return (len);
}
