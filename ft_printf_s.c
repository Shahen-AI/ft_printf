/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:40:01 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:40:02 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(va_list argument, t_flags *flag)
{
	int		out;
	char	*str;
	int		i;
	int		spaces;

	out = 0;
	i = -1;
	str = va_arg(argument, char *);
	if (!str)
		str = "(null)";
	flag->dot = (flag->dot > ft_strlen(str) ||
		flag->dot < 0 ? ft_strlen(str) : flag->dot);
	spaces = flag->digit - flag->dot;
	if (flag->digit && spaces > 0 && !flag->minus)
		while (spaces--)
			out += ft_putchar(' ');
	if (flag->dot > 0)
		while (flag->dot-- && str[++i])
			out += ft_putchar(str[i]);
	else if (flag->dot < 0)
		out += ft_putstr(str);
	if (flag->minus && flag->digit && spaces > 0)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}
