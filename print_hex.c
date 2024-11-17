/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:24:24 by salahian          #+#    #+#             */
/*   Updated: 2024/11/17 16:58:17 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_hex(va_list arg)
{
	unsigned int	s;

	s = va_arg(arg, unsigned int);
	return (s);
}

int	help_to_print_hex(char *s, int count, int zero, t_flags *flag)
{
	int	i;
	int	j;
	int	sum;

	j = 0;
	sum = 0;
	if (flag->hashtag_flag && zero != 1)
	{
		sum += ft_print('0');
		sum += ft_print('x');
	}
	if (flag->precision != (unsigned int)-1 && (int)flag->precision > count)
	{
		while (j < ((int)flag->precision - count))
		{
			sum += ft_print('0');
			j++;
		}
	}
	i = 0;
	while (i < count && (flag->precision != 0 || s[0] != '0'))
		sum += ft_print(s[i++]);
	return (sum);
}

int	handle_minus_flag_hex(char *s, int count, int zero, t_flags *flag)
{
	int	sum;
	int	i;

	sum = 0;
	sum += help_to_print_hex(s, count, zero, flag);
	i = flag->width - sum;
	while (i-- > 0)
	{
		sum += ft_print(' ');
	}
	return (sum);
}

int	handle_others_flag_hex(char *s, int count, int zero, t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	i = flag->width - count;
	if (flag->precision != (unsigned int)-1 && (int)flag->precision > count)
		i = i - ((int)flag->precision - count);
	if (flag->hashtag_flag && zero != 1)
		i -= 2;
	if ((zero == 1 && flag->precision == 0))
		i++;
	while (i-- > 0)
	{
		if (flag->zero_flag)
			sum += ft_print('0');
		else
			sum += ft_print(' ');
	}
	sum += help_to_print_hex(s, count, zero, flag);
	return (sum);
}

int	print_hex(va_list arg, char p, t_flags *flag)
{
	unsigned int	count;
	size_t			sum;
	int				zero;
	char			s[20];

	sum = 0;
	count = get_hex(arg);
	zero = 0;
	ft_get_add(count, s, p);
	if (s[0] == '0' && s[1] == '\0')
		zero = 1;
	count = ft_strlen(s);
	if (flag->minus_flag)
		sum += handle_minus_flag_hex(s, (int)count, zero, flag);
	else
		sum += handle_others_flag_hex(s, (int)count, zero, flag);
	return ((int)sum);
}
