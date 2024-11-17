/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:12:46 by soulaimane        #+#    #+#             */
/*   Updated: 2024/11/14 17:22:08 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int					ft_print(char c);
int					ft_error(int a);
int					ft_printf(const char *s, ...);
int					ft_atoi(const char *str);
char				*get_string(va_list arg);
int					help_others_flag(char *s, int i, int sign, t_flags *flag);
char				*get_charcter(va_list arg);
int					ft_isdigit(int c);
void				ft_itoa_static2(long n, char *buffer);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					print_add(va_list arg, char p, t_flags *flag);
int					print_hex(va_list arg, char p, t_flags *flag);
int					print_string(va_list arg, char p, t_flags *flag);
int					print_unsigned(va_list arg, t_flags *flag);
int					print_integer(va_list arg, t_flags *flag);
int					get_flag(char *p, t_flags *flag);
char				*get_width(char *s, t_flags *flag);
char				*get_precision(char *s, t_flags *flag);
int					counter_add(unsigned long long n);
void				ft_get_add(unsigned long long count, char *s, char p);

#endif