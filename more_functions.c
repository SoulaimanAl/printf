/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:58 by salahian          #+#    #+#             */
/*   Updated: 2024/11/16 14:35:52 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter_add(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_get_add(unsigned long long count, char *s, char p)
{
	const char	*x;
	int			i;

	x = "0123456789abcdef";
	if (p == 'X')
		x = "0123456789ABCDEF";
	i = counter_add(count);
	s[i] = '\0';
	i--;
	if (count == 0)
	{
		s[0] = '0';
		return ;
	}
	while (count != 0)
	{
		s[i--] = x[count % 16];
		count /= 16;
	}
}
