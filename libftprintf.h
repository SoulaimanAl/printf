/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:12:46 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/14 08:56:34 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct flags
{
	int				hashtag_flag;
	int				minus_flag;
	int				plus_flag;
	int				zero_flag;
	int				space_flag;

	unsigned int	precision;
	int				width;
}					t_flags;

int					ft_printf(const char *s, ...);
int					ft_atoi(const char *str);
char				*ft_itoa1(int n);
int					ft_isdigit(int c);
char				*ft_itoa(long n);
size_t				ft_strlen(const char *str);
int					print_add(va_list arg, char p, t_flags *flag);
int					print_hex(va_list arg, char p, t_flags *flag);
int					print_string(va_list arg, char p, t_flags *flag);
int					print_unsigned(va_list arg, char p, t_flags *flag);
char				*ft_strdup(const char *s1);
int					print_integer(va_list arg, char p, t_flags *flag);
int					get_flag(char *p, t_flags *flag);
char				*get_width(va_list arg, char *s, t_flags *flag);
char				*get_precision(va_list arg, char *s, t_flags *flag);
#endif