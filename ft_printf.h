/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:40:54 by ster-min          #+#    #+#             */
/*   Updated: 2021/03/10 15:40:56 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long int	t_ul;
typedef struct	s_flags
{
	int			star;
	int			minus;
	int			zero;
	int			dot;
	int			len;
	int			digit;
}				t_flags;

int				ft_isdigit(int c);
int				ft_printf(const char *format, ...);
int				ft_printf_c(va_list argument, t_flags *flag);
int				ft_printf_s(va_list argument, t_flags *flag);
int				ft_printf_p(va_list argument, t_flags *flag);
int				ft_printf_d(va_list argument, t_flags *flag);
int				ft_printf_u(va_list argument, t_flags *flag);
int				ft_printf_hex(va_list argument, t_flags *flag, char format);
int				ft_printf_percent(t_flags *flag);
void			ft_flag_star(va_list argument, t_flags *flag);
void			init(t_flags *flag);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_strlen(const char *s);
char			*ft_itoa(int n);
int				int_len(int n);
int				int_len_x(int n);
int				int_len_u(unsigned int n);
int				int_len_p(t_ul n);
char			*ft_itoa_u(unsigned int n);
int				flag_check_first(const char *format, int i,
		t_flags *flag, va_list arg);
int				flag_check_second(const char *format, int i,
		t_flags *flag, va_list arg);
int				conv_check(const char *format, int i,
		va_list arg, t_flags *flag);
int				ft_d_flag(int a, t_flags *flag, int zero, int spaces);
int				ft_hex_flag(int zeros, t_flags *flag,
		int zero, int spaces);
int				ft_u_flag(unsigned int a, t_flags *flag,
		int zero, int spaces);
int				ft_d_zero(int out, t_flags *flag);
int				ft_x_zero(int out, t_flags *flag);
int				ft_u_zero(int out, t_flags *flag);
int				ft_dig(long n, int len, char *base);
int				ft_dig_p(t_ul n, int len, char *base);
int				ft_putnbr_base_x(unsigned int nbr, char format);
int				ft_putnbr_base_p(t_ul nbr);
int				ft_u_out(unsigned int a, int out);
int				ft_d_out(int a, int out);

#endif
