/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:57:16 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/17 16:05:44 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_minus_flag_instring(char *s, int count, t_flags *flag)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (i < count)
	{
		ft_print(s[i]);
		i++;
	}
	sum += count;
	i = flag->width - count;
	while (i > 0)
	{
		sum += ft_print(' ');
		i--;
	}
	return (sum);
}

int	handle_others_flag_instring(char *s, int count, t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	i = flag->width - count;
	while (i > 0)
	{
		if (!flag->zero_flag)
			sum += ft_print(' ');
		else
			sum += ft_print('0');
		i--;
	}
	i = 0;
	while (i < count)
	{
		ft_print(s[i]);
		sum++;
		i++;
	}
	return (sum);
}

int	help_string(char *s, t_flags *flag, int count)
{
	int	sum;
	int	check;

	sum = 0;
	check = 0;
	count += ft_strlen(s);
	if (flag->precision != (unsigned int)-1
		&& flag->precision < (unsigned int)count)
		count = (int)flag->precision;
	if (flag->minus_flag)
		sum += handle_minus_flag_instring(s, count, flag);
	else
		sum += handle_others_flag_instring(s, count, flag);
	return (sum);
}

int	print_string(va_list arg, char p, t_flags *flag)
{
	size_t	count;
	size_t	sum;
	char	*s;

	sum = 0;
	count = 0;
	if (p == 's')
		s = get_string(arg);
	else
	{
		s = get_charcter(arg);
		if (s[0] == '\0')
			count++;
	}
	sum += help_string(s, flag, (int)count);
	return (sum);
}
