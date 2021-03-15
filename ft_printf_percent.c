/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:39:50 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:39:52 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_star(va_list argument, t_flags *flag)
{
	int	a;

	a = va_arg(argument, int);
	if (a < 0)
		flag->minus = 1;
	if (flag->dot == -1 && a < 0)
		flag->digit = -a;
	else if (flag->dot == -1)
		flag->digit = a;
	else
		flag->dot = a;
}

int		ft_printf_percent(t_flags *flag)
{
	int		out;
	int		spaces;
	char	zero;

	out = 0;
	zero = ' ';
	spaces = flag->digit - 1;
	if (flag->zero)
		zero = '0';
	if (flag->digit && spaces > 0 && !flag->minus)
		while (spaces--)
			out += ft_putchar(zero);
	out += ft_putchar('%');
	if (flag->digit && spaces > 0 && flag->minus)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}
