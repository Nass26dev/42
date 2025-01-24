/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:11:00 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 11:27:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_count
{
	size_t	i;
	size_t	nb;
	ssize_t	error;
}			t_count;

int			ft_printf(const char *str, ...);
int			char_is_flag(char c);
t_count		init_count(t_count count);
t_count		select_function(va_list args, t_count count, char *str);
t_count		ft_putstr(char *str, t_count count);
t_count		ft_putchar(char c, t_count count);
t_count		print_ptr(va_list args, t_count count);
char		*reverse_str(char *str);
int			buffer_len(unsigned long long int nb);
t_count		ft_put_free_str(char *str, t_count count);
t_count		print_in_hexa(va_list args, char c, t_count count);
char		*convert_base_16(unsigned long long int nb, char c);
t_count		ft_unsigned_putnbr(unsigned int n, t_count *count);
t_count		ft_putnbr(int n, t_count *count);
ssize_t		ft_strlen(char *str);

#endif