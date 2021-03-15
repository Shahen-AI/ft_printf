/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:39:00 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:39:02 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_u_out(unsigned int a, int out)
{
	char *str;

	str = ft_itoa_u(a);
	out += ft_putstr(str);
	free(str);
	return (out);
}

int	ft_printf_c(va_list argument, t_flags *flag)
{
	int a;
	int count;
	int	out;

	out = 0;
	count = flag->digit - 1;
	a = va_arg(argument, int);
	if (flag->minus)
		out += ft_putchar(a);
	if (flag->digit)
		while (count--)
			out += ft_putchar(' ');
	if (!flag->minus)
		out += ft_putchar(a);
	return (out);
}
