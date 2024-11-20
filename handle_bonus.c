/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:33:56 by salahian          #+#    #+#             */
/*   Updated: 2024/11/19 18:17:47 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error(int a)
{
	static int	c;

	if (a != 0)
		c = a;
	return (c);
}

int	ft_print(char c)
{
	if (ft_error(0) != -1)
		ft_error(write(1, &c, 1));
	return (ft_error(0));
}

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

char	*get_width(char *s, t_flags *flag)
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

char	*get_precision(char *s, t_flags *flag)
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
