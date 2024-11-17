/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:11:44 by salahian          #+#    #+#             */
/*   Updated: 2024/11/17 15:24:13 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
