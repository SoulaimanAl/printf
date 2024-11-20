/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:20:48 by salahian          #+#    #+#             */
/*   Updated: 2024/11/19 19:06:30 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	help_others_flag(int i, int sign, t_flags *flag)
{
	int	sum;

	sum = 0;
	if (flag->space_flag && sign != 1)
	{
		flag->space_flag = 0;
		sum += ft_print(' ');
	}
	while (i > 0)
	{
		if (flag->zero_flag && flag->precision == (unsigned int)-1)
			sum += ft_print('0');
		else
			sum += ft_print(' ');
		i--;
	}
	if (sign == 1 && flag->sign_flag)
		sum += ft_print('-');
	if (flag->plus_flag && sign != 1)
	{
		sum += ft_print('+');
		flag->plus_flag = 0;
	}
	return (sum);
}

int	help_to_print_int(int count, int sign, t_flags *flag)
{
	int	sum;

	sum = 0;
	if (sign == 1)
	{
		if (flag->zero_flag && flag->precision == (unsigned int)-1)
		{
			flag->sign_flag = 0;
			sum += ft_print('-');
		}
		else if (flag->width > count)
			;
		else
		{
			sum += ft_print('-');
			flag->sign_flag = 0;
		}
	}
	if (flag->plus_flag && sign != 1 && flag->zero_flag
		&& flag->precision == (unsigned int)-1)
	{
		sum += ft_print('+');
		flag->plus_flag = 0;
	}
	return (sum);
}

int	help_handle_others_hex(char *s, int i, int zero, t_flags *flag)
{
	int	sum;
	int	count;

	sum = 0;
	count = (int)ft_strlen(s);
	while (i-- > 0)
	{
		if (flag->zero_flag && flag->precision == (unsigned int)-1)
			sum += ft_print('0');
		else
			sum += ft_print(' ');
	}
	sum += help_to_print_hex(s, count, zero, flag);
	return (sum);
}

char	*get_string(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (s == NULL)
		s = "(null)";
	return (s);
}

char	*get_charcter(va_list arg)
{
	static char	c[2];

	c[0] = (char)va_arg(arg, int);
	c[1] = '\0';
	return (c);
}
