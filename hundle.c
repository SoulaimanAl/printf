/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:33:56 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/14 09:35:29 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_flag(char *p, t_flags *flag)
{
	int	i;

	i = 0;
	while ((*p == '+') || (*p == '-') || (*p == '0') || (*p == '#')
		|| (*p == ' '))
	{
		if (*p == '+')
			flag->plus_flag = 1;
		else if (*p == '-')
			flag->minus_flag = 1;
		else if (*p == '0')
			flag->zero_flag = 1;
		else if (*p == '#')
			flag->hashtag_flag = 1;
		else if (*p == ' ')
			flag->space_flag = 1;
		i = 1;
		p++;
	}
	return (i);
}

char	*get_width(va_list arg, char *s, t_flags *flag)
{
	if (flag->width < 0)
	{
		flag->width = -flag->width;
		flag->minus_flag = 1;
		return (s + 1);
	}
	flag->width = 0;
	while (*s >= '0' && *s <= '9')
	{
		flag->width = flag->width * 10 + (*s - '0');
		s++;
	}
	return (s);
}

char	*get_precision(va_list arg, char *s, t_flags *flag)
{
	if (*s != '.')
		return (s);
	s++;
	flag->precision = 0;
	while (*s >= '0' && *s <= '9')
	{
		flag->precision = flag->precision * 10 + (*s - '0');
		s++;
	}
	return (s);
}
