/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:40:22 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:40:24 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_u_flag(unsigned int a, t_flags *flag, int zero, int spaces)
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
	if (!flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(zero);
	if (a < 0 && zero == ' ')
	{
		out += ft_putchar('-');
		a = -a;
	}
	return (out);
}

int		ft_u_zero(int out, t_flags *flag)
{
	if ((flag->dot != 0 && flag->digit) || (flag->dot && !flag->digit))
		out += ft_putchar('0');
	else if (!flag->digit && flag->dot == 0)
		return (out);
	else
		out += ft_putchar(' ');
	return (out);
}

int		int_len_u(unsigned int n)
{
	int len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	len = int_len_u(nbr);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= (-1);
	}
	else if (nbr == 0)
		res[0] = '0';
	res[len] = '\0';
	while (len > 0 && nbr != 0)
	{
		--len;
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

int		ft_printf_u(va_list argument, t_flags *flag)
{
	int				out;
	int				spaces;
	unsigned int	a;
	int				zeros;
	char			zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, unsigned int);
	zeros = (flag->dot - int_len_u(a) < 0 ? 0 : flag->dot - int_len_u(a));
	spaces = flag->digit - int_len_u(a) - zeros;
	if (a < 0)
		--spaces;
	out += ft_u_flag(a, flag, zero, spaces);
	while (zeros--)
		out += ft_putchar('0');
	if (a != 0)
		out = ft_u_out(a, out);
	else
		out = ft_u_zero(out, flag);
	if (flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}
