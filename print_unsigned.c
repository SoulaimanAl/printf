/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:21:29 by salahian          #+#    #+#             */
/*   Updated: 2024/11/17 16:06:12 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_unsigned(va_list arg)
{
	unsigned int	s;

	s = va_arg(arg, unsigned int);
	return (s);
}

int	help_to_print_unsigned(char *s, int count, t_flags *flag)
{
	int	i;
	int	j;
	int	sum;

	j = 0;
	sum = 0;
	if (flag->precision != (unsigned int)-1
		&& flag->precision > (unsigned int)count)
	{
		while ((unsigned int)j < (flag->precision - count))
		{
			sum += ft_print('0');
			j++;
		}
	}
	i = 0;
	if (flag->space_flag)
		sum += ft_print(' ');
	while (i < count)
	{
		sum += ft_print(s[i]);
		i++;
	}
	return (sum);
}

int	handle_minus_flag_unsigned(char *s, int count, t_flags *flag)
{
	int	sum;
	int	i;

	sum = 0;
	sum += help_to_print_unsigned(s, count, flag);
	i = flag->width - sum;
	while (i-- > 0)
	{
		sum += ft_print(' ');
	}
	return (sum);
}

int	handle_others_flag_unsigned(char *s, int count, t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	i = flag->width - count;
	if (flag->precision != (unsigned int)-1
		&& flag->precision > (unsigned int)count)
		i = i - ((int)flag->precision - count);
	while (i-- > 0)
		sum += ft_print(' ');
	sum += help_to_print_unsigned(s, count, flag);
	return (sum);
}

int	print_unsigned(va_list arg, t_flags *flag)
{
	unsigned int	count;
	size_t			sum;
	char			s[11];

	sum = 0;
	count = get_unsigned(arg);
	ft_itoa_static2(count, s);
	count = ft_strlen(s);
	if (flag->minus_flag)
		sum += handle_minus_flag_unsigned(s, (int)count, flag);
	else
		sum += handle_others_flag_unsigned(s, (int)count, flag);
	return ((int)sum);
}
