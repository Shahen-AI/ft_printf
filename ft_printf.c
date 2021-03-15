/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:40:46 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:40:48 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_flags *flag)
{
	flag->dot = -1;
	flag->minus = 0;
	flag->star = 0;
	flag->zero = 0;
	flag->len = 0;
	flag->digit = 0;
}

int		flag_check_first(const char *format, int i, t_flags *flag, va_list arg)
{
	if (format[i] == '0')
	{
		flag->zero = 1;
		++i;
	}
	if (format[i] == '-')
	{
		flag->minus = 1;
		++i;
	}
	if (format[i] == '0')
	{
		flag->zero = 1;
		++i;
	}
	if (format[i] == '*')
	{
		ft_flag_star(arg, flag);
		++i;
	}
	i = flag_check_second(format, i, flag, arg);
	return (i);
}

int		flag_check_second(const char *format, int i, t_flags *flag, va_list arg)
{
	while (ft_isdigit(format[i]))
	{
		flag->digit = flag->digit * 10 + (format[i] - '0');
		++i;
	}
	if (format[i] == '.')
	{
		flag->dot = 0;
		++i;
		if (format[i] == '*')
		{
			ft_flag_star(arg, flag);
			++i;
		}
		while (ft_isdigit(format[i]))
		{
			flag->dot = flag->dot * 10 + (format[i] - '0');
			++i;
		}
	}
	return (i);
}

int		conv_check(const char *format, int i, va_list arg, t_flags *flag)
{
	int out;

	out = 0;
	if (format[i] == 'c')
		out += ft_printf_c(arg, flag);
	else if (format[i] == 's')
		out += ft_printf_s(arg, flag);
	else if (format[i] == 'p')
		out += ft_printf_p(arg, flag);
	else if (format[i] == 'd' || format[i] == 'i')
		out += ft_printf_d(arg, flag);
	else if (format[i] == 'u')
		out += ft_printf_u(arg, flag);
	else if (format[i] == 'x' || format[i] == 'X')
		out += ft_printf_hex(arg, flag, format[i]);
	else if (format[i] == '%')
		out += ft_printf_percent(flag);
	return (out);
}

int		ft_printf(const char *format, ...)
{
	va_list arguments;
	t_flags	flag;
	int		count_bytes;
	int		i;

	count_bytes = 0;
	i = -1;
	va_start(arguments, format);
	while (format[++i])
	{
		if (format[i] != '%')
			count_bytes += ft_putchar(format[i]);
		else
		{
			init(&flag);
			i = flag_check_first(format, i + 1, &flag, arguments);
			count_bytes += conv_check(format, i, arguments, &flag);
		}
	}
	va_end(arguments);
	return (count_bytes);
}
