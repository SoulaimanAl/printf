/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:20:48 by salahian          #+#    #+#             */
/*   Updated: 2024/11/17 15:26:13 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	help_others_flag(char *s, int i, int sign, t_flags *flag)
{
	int	sum;

	(void)s;
	sum = 0;
	while (i-- > 0)
	{
		if (!flag->zero_flag)
			sum += ft_print(' ');
		else
			sum += ft_print('0');
	}
	if (sign == 1 && !flag->zero_flag)
		sum += ft_print('-');
	if (flag->plus_flag && sign != 1)
	{
		sum += ft_print('+');
		flag->plus_flag = 0;
	}
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
