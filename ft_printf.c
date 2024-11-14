/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:05:02 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/14 11:35:34 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	print(char *c, char *s)
{
	int	i;

	i = 0;
	while (c <= s)
	{
		i += write(1, c, 1);
		c++;
	}
	return (i);
}
int	call_function(va_list arg, char s, t_flags *flag)
{
	int	count;

	count = 0;
	if (s == 's' || s == 'c')
		count += print_string(arg, s, flag);
	else if (s == 'd' || s == 'i')
		count += print_integer(arg, s, flag);
	else if (s == 'u')
		count += print_unsigned(arg, s, flag);
	else if (s == 'x' || s == 'X')
		count += print_hex(arg, s, flag);
	else if (s == 'p')
		count += print_add(arg, s, flag);
	else if (s == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}
int	ft_printf(const char *s, ...)
{
	va_list arg;
	char 	*p;
	int 	count;
	int		check;
	t_flags *flag;

	if (s == NULL || s[0] == '\0' || (s[0] == '%' && s[1] == '\0'))
		return (0);
	count = 0;
	check = 0;
	va_start(arg, s);
	flag = malloc(sizeof(t_flags));
	if (flag == NULL)
		return (-1);
	while (*s != '\0')
	{
		sett(flag);
		if (*s != '%')
			count += write(1, s, 1);
		else
		{
			s++;
			p = (char *)s;
			if (*s == '\0')
				return (count);
			while (get_flag((char *)s, flag))
				s++;
			s = get_width(arg, (char *)s, flag);
			s = get_precision(arg, (char *)s, flag);
			check = call_function(arg, (char)*s, flag);
			if (check == -1)
				count += print(p, (char *)s);
			else
				count += check;
		}
		s++;
	}
	va_end(arg);
	free(flag);
	return (count);
}