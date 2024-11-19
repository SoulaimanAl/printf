/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:56:00 by salahian          #+#    #+#             */
/*   Updated: 2024/11/17 16:57:38 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	get_add(va_list arg)
{
	unsigned long	s;

	s = va_arg(arg, unsigned long long);
	return (s);
}

int	help_to_print_add(char *s, unsigned long long count, t_flags *flag)
{
	int	i;
	int	j;
	int	sum;

	j = 0;
	sum = 0;
	i = 0;
	if (flag->hashtag_flag && !(flag->zero_flag
			&& (flag->precision == (unsigned int)-1)))
	{
		sum += ft_print('0');
		sum += ft_print('x');
	}
	if (flag->precision != (unsigned int)-1
		&& flag->precision > (unsigned int)count)
	{
		while ((unsigned int)j < (flag->precision - count))
		{
			sum += ft_print('0');
			j++;
		}
	}
	while (i < (int)count && (flag->precision != 0 || s[0] != '0'))
		sum += ft_print(s[i++]);
	return (sum);
}

int	handle_minus_flag_add(char *s, unsigned long long count, t_flags *flag)
{
	int	sum;
	int	i;

	sum = 0;
	sum += help_to_print_add(s, count, flag);
	i = flag->width - sum;
	while (i-- > 0)
	{
		sum += ft_print(' ');
	}
	return (sum);
}

int	handle_others_flag_add(char *s, unsigned long long count, int zero,
		t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	i = flag->width - count;
	if (flag->precision != (unsigned int)-1
		&& flag->precision > (unsigned int)count)
		i = i - (flag->precision - count);
	if ((flag->hashtag_flag && zero != 1) || zero)
		i -= 2;
	if (flag->hashtag_flag && flag->zero_flag
		&& (flag->precision == (unsigned int)-1))
	{
		sum += ft_print('0');
		sum += ft_print('x');
	}
	while (i-- > 0)
	{
		if (flag->zero_flag && ((flag->precision == (unsigned int)-1)
				|| (flag->precision != 0)))
			sum += ft_print('0');
		else
			sum += ft_print(' ');
	}
	return (sum += help_to_print_add(s, count, flag), sum);
}

int	print_add(va_list arg, char p, t_flags *flag)
{
	unsigned long long	count;
	size_t				sum;
	int					zero;
	char				s[20];

	sum = 0;
	zero = 0;
	count = get_add(arg);
	flag->hashtag_flag = 1;
	ft_get_add(count, s, p);
	if (s[0] == '0' && s[1] == '\0')
		zero = 1;
	count = ft_strlen(s);
	if (flag->minus_flag)
		sum += handle_minus_flag_add(s, count, flag);
	else
		sum += handle_others_flag_add(s, count, zero, flag);
	return ((int)sum);
}
