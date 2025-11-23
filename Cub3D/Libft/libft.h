/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:24:13 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/21 18:24:13 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *src, size_t nb);
int		ft_isalnum(char a);
int		ft_isalpha(char a);
int		ft_isascii(char a);
int		ft_isdigit(char a);
int		ft_isprint(char a);
char	*ft_itoa(int nb);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nb, size_t size);
void	*ft_memchr(const void *find, int tofind, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t nb);
void	*ft_memmove(void *dest, const void *src, size_t nb);
void	*ft_memset(void *source, int neww, size_t nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *find, int tofind);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t nb);
char	*ft_strnstr(const char *find, const char *tofind, size_t nb);
char	*ft_strrchr(const char *find, int tofind);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int cara);
int		ft_tolower(int cara);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
int		findnewline(char *str);
char	*get_next_line(int fd);
int		ft_print_ptr(long long int ptr);
int		ft_print_hex(unsigned int nb, char size);
int		ft_print_ultimate(long long int n);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_get_strjoin(const char *s1, const char *s2);
char	*ft_get_strlcpy(char *dst, const char *src, size_t size);

#endif