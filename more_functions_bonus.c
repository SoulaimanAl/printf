/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:58 by salahian          #+#    #+#             */
/*   Updated: 2024/11/19 18:03:31 by salahian         ###   ########.fr       */
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

void	rev(char *s, int i)
{
	int		j;
	char	c;

	j = 0;
	i -= 1;
	while (j <= i)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i--;
		j++;
	}
}

void	check(char *s, char *buffer, int i, int sign)
{
	int	j;

	if (sign == 1)
		s[i++] = '-';
	s[i] = '\0';
	rev(s, i);
	j = 0;
	while (s[j] != '\0')
	{
		buffer[j] = s[j];
		j++;
	}
	buffer[j] = '\0';
}

void	ft_itoa_static2(long n, char *buffer)
{
	int		i;
	int		sign;
	char	temp[20];

	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return ;
	}
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	i = 0;
	while (n != 0)
	{
		temp[i++] = (n % 10) + '0';
		n /= 10;
	}
	check(temp, buffer, i, sign);
}
