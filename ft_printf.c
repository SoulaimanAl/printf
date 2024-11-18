/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulaimane <soulaimane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:05:02 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/18 10:08:00 by soulaimane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sett(t_flags *flag)
{
	flag->hashtag_flag = 0;
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->zero_flag = 0;
	flag->space_flag = 0;
	flag->precision = (unsigned int)-1;
	flag->width = 0;
}

/*int	print_res(char *c, char *s)
{
	int	i;

	i = 0;
	while (c <= s)
	{
		i += ft_print(*c);
		c++;
	}
	return (i);
}*/

int	call_function(va_list arg, char *s, t_flags *flag)
{
	int	count;

	count = 0;
	if (*s == 's' || *s == 'c')
		count += print_string(arg, *s, flag);
	else if (*s == 'd' || *s == 'i')
		count += print_integer(arg, flag);
	else if (*s == 'u')
		count += print_unsigned(arg, flag);
	else if (*s == 'x' || *s == 'X')
		count += print_hex(arg, *s, flag);
	else if (*s == 'p')
		count += print_add(arg, *s, flag);
	else
		count += print_res(*s, flag);
	return (count);
}

int	help_printf(va_list arg, char *s, t_flags *flag)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		sett(flag);
		if (*s != '%')
			count += ft_print(*s);
		else
		{
			s++;
			if (*s == '\0')
			{
				return (free(flag), count);
			}
			while (get_flag((char *)s, flag))
				s++;
			s = get_width((char *)s, flag);
			s = get_precision((char *)s, flag);
			count += call_function(arg, (char *)s, flag);
		}
		s++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;
	t_flags	*flag;

	if (s == NULL || (s[0] == '%' && s[1] == '\0'))
		return (-1);
	count = 0;
	ft_error(1);
	va_start(arg, s);
	flag = malloc(sizeof(t_flags));
	if (flag == NULL)
		return (-1);
	count += help_printf(arg, (char *)s, flag);
	va_end(arg);
	free(flag);
	if (ft_error(0) == -1)
		return (-1);
	return (count);
}
