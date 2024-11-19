/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:00:14 by salahian          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:44 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_integer(va_list arg)
{
	int	s;

	s = va_arg(arg, int);
	return (s);
}

int	help_to_print(char *s, int count, int sign, t_flags *flag)
{
	int	j;
	int	sum;

	j = 0;
	sum = 0;
	if (flag->space_flag && sign != 1)
		sum += ft_print(' ');
	if (flag->precision != (unsigned int)-1 && (int)flag->precision > (count
			- sign))
	{
		while (j < (((int)flag->precision - (count - sign))))
		{
			sum += ft_print('0');
			j++;
		}
	}
	j = 0;
	if (sign)
		j++;
	while (j < count && (flag->precision != 0 || s[0] != '0'))
		sum += ft_print(s[j++]);
	return (sum);
}

int	handle_minus_flag(char *s, int count, int sign, t_flags *flag)
{
	int	sum;
	int	i;

	sum = 0;
	if (flag->plus_flag && sign != 1)
	{
		sum += ft_print('+');
		flag->plus_flag = 0;
	}
	if (sign == 1)
		sum += ft_print('-');
	sum += help_to_print(s, count, sign, flag);
	i = flag->width - sum;
	while (i-- > 0)
	{
		sum += ft_print(' ');
	}
	return (sum);
}

int	handle_others_flag(char *s, int count, int sign, t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	if (s[0] == '0' && s[1] == '\0' && flag->precision == 0)
		count--;
	if (sign == 0)
		i = flag->width - count - flag->space_flag;
	else
		i = flag->width - count;
	if (flag->plus_flag && sign != 1)
		i--;
	if (flag->precision != (unsigned int)-1
		&& flag->precision >= (unsigned int)count)
		i = i - ((int)flag->precision - count) - sign;
	sum += help_to_print_int(s, count, sign, flag);
	sum += help_others_flag(s, i, sign, flag);
	sum += help_to_print(s, count, sign, flag);
	return (sum);
}

int	print_integer(va_list arg, t_flags *flag)
{
	int		count;
	size_t	sum;
	char	s[12];
	int		sign;

	sum = 0;
	sign = 0;
	count = get_integer(arg);
	ft_itoa_static2(count, s);
	if (s[0] == '-')
	{
		sign = 1;
		flag->sign_flag = 1;
	}
	count = ft_strlen(s);
	if (flag->minus_flag)
		sum += handle_minus_flag(s, count, sign, flag);
	else
		sum += handle_others_flag(s, count, sign, flag);
	return ((int)sum);
}
