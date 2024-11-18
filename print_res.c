/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulaimane <soulaimane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:34:48 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/18 10:43:36 by soulaimane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hundle_others(char s, t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	if (flag->zero_flag)
	{
		while (i < flag->width - 1)
		{
			sum += ft_print('0');
			i++;
		}
		sum += ft_print(s);
		return (sum);
	}
	i = 0;
	while (i < flag->width - 1)
	{
		sum += ft_print(' ');
		i++;
	}
	sum += ft_print(s);
	return (sum);
}

int	print_res(char s, t_flags *flag)
{
	int	i;
	int	sum;

	sum = 0;
	if (flag->minus_flag)
	{
		if (flag->width)
		{
			i = 0;
			sum += ft_print(s);
			while (i < flag->width - 1)
			{
				sum += ft_print(' ');
				i++;
			}
		}
	}
	else
		sum += hundle_others(s, flag);
	return (sum);
}
